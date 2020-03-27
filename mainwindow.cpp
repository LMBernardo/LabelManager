#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingswindow.h"

#include "utils.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainUI)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init(){

    QSettings settings;

    icon = new QIcon();
    foreach( const QString &imageName, QDir(":/icons").entryList()){
        int width = imageName.split("-")[1].split(".")[0].toInt();
        QSize size = {width, width};
        icon->addFile(":/icons/" + imageName, size);
    }

    this->setWindowIcon(icon->pixmap({32,32}));

    sysTray = new QSystemTrayIcon;
    sysTray->setIcon(icon->pixmap({32,32}));

    if (QSysInfo::productType() != "osx"){
        sysTrayMenu = new QMenu(this);
        sysTrayMenu->addAction("Exit", this, &MainWindow::on_contextMenuExit);
        sysTray->setContextMenu(sysTrayMenu);
    }
    QObject::connect(sysTray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(on_sysTrayActivated(QSystemTrayIcon::ActivationReason)));

    if (settings.value("MainSettings/enableSystemTrayIcon").toBool()) sysTray->show();
    else sysTray->hide();

    ui->lpnStatus->setVisible(false);
    ui->skuStatus->setVisible(false);
    utils.initSettings(this);

    lClient = new labelClient(this);
    lServer = new labelServer(this, static_cast<unsigned short>(settings.value("MainSettings/listenPort").toInt()));

    wsServer = new webSocket(9458, this);
    connect(wsServer, &webSocket::wsMessageReceived, this, &MainWindow::on_wsMessageReceived);

    if (settings.value("MainSettings/startMinimized").toBool()) this->showMinimized();

}

void MainWindow::on_settingsChange(const QString sFile){
    // Don't complain about not using sFile
    (void) sFile;
    qInfo() << "Settings file changed, updating..";
    updateUi();
}

void MainWindow::updateUi(){

    QSettings settings;

    settings.sync();
    settings.beginGroup("MainSettings");

    if (settings.value("enableSystemTrayIcon").toBool()) sysTray->show();
    else sysTray->hide();

    if (settings.value("remoteMode").toBool() ){
        //ui->fetchLPNButton->setEnabled(true);
        ui->fetchSKUButton->setEnabled(true);
        ui->skuLineEdit->setPlaceholderText("Fetch to populate");
        // Remote server code here
    } else {
        //ui->fetchLPNButton->setEnabled(false);
        ui->fetchSKUButton->setEnabled(false);
        ui->skuLineEdit->setPlaceholderText("");
    }

    QString lpnString = Utils::getFullLPN(settings.value("currentPrefix").toString());
    ui->lpnLineEdit->setText(lpnString);

    settings.endGroup();

    settings.beginGroup("UI");
    ui->lpnQuantitySpinBox->setValue( settings.value("printQuantity").toList().at(0).toInt() );
    ui->skuQuantitySpinBox->setValue( settings.value("printQuantity").toList().at(1).toInt() );
    ui->textQuantitySpinBox->setValue( settings.value("printQuantity").toList().at(2).toInt() );
    settings.endGroup();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    if (QMessageBox::question(this, "Exit Confirmation", "Are you sure you want to exit?") == QMessageBox::Yes){
        event->accept();
    }
}

void MainWindow::changeEvent(QEvent *event)
{
    QSettings settings;
    if (settings.value("MainSettings/enableSystemTrayIcon").toBool() && settings.value("MainSettings/minimizeToSystemTray").toBool()){
        if (event->type() == QEvent::WindowStateChange){
            QWindowStateChangeEvent* e = static_cast<QWindowStateChangeEvent*>(event);
            if (e->oldState() != Qt::WindowMinimized && isMinimized()){
                QTimer::singleShot(0, this, SLOT(hide()));
                event->ignore();
                return;
            }
        }
    }
    QMainWindow::changeEvent(event);
}

void MainWindow::on_contextMenuExit()
{
    this->close();
}

void MainWindow::on_sysTrayActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (QSysInfo::productType() == "osx"){
        if (this->isVisible()) this->hide();
        else this->showNormal();
    } else if (reason == QSystemTrayIcon::DoubleClick){
        if (this->isVisible()) this->hide();
        else this->showNormal();
    }
}

int MainWindow::printLabel(QString command, QString label){
    QSettings settings;
    if (settings.value("MainSettings/usePrintCommand").toBool() == false) {
        return -9;
    } else {
        QStringList commandList = command.split(" ");
        QString program = commandList.at(0);
        QStringList arguments;
        for (int i = 1; i < commandList.size(); i++){
            if (commandList.at(i) == "$PRINTER_NAME") arguments.push_back(settings.value("MainSettings/printerName").toString());
            //else if (commandList.at(i) == "$FULL_LPN") arguments.push_back(ui->lpnLineEdit->text());
            else arguments.push_back(commandList.at(i));
        }
        arguments.push_back(label);
        qInfo() << "Command: " << program << arguments;
        QProcess *printProcess = new QProcess(this);
        if (settings.value("MainSettings/systemTrayNotifications").toBool() && settings.value("MainSettings/enableSystemTrayIcon").toBool())
            sysTray->showMessage("Printing...", "Printing \"" + label + "\"", QSystemTrayIcon::Information, 3000);
        return printProcess->execute(program, arguments);
    }
}

void MainWindow::on_actionSettings_triggered()
{
    SettingsWindow s;
    s.setFixedHeight(225);
    //s.setFixedWidth(415);
    s.initSettingsWindow();
    s.exec();
    updateUi();

}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

//void MainWindow::on_lpnLineEdit_returnPressed()
//{
//    emit on_printLPNButton_released();
//}

void MainWindow::on_printLPNButton_released()
{
    ui->printLPNButton->setEnabled(false);
    QSettings settings;
    QClipboard *clipboard = QApplication::clipboard();
    QString prefix = settings.value("MainSettings/currentPrefix").toString();
    //QString lpnString = Utils::getFullLPN(prefix);
    QVariantMap lpnMap = settings.value("MainSettings/lpnMap").toMap();
    int status = 0;
    int currentLPN = Utils::getLPN(prefix);
    QString lpnString = Utils::lpnPrefix(prefix, settings.value("MainSettings/lpnPadding").toInt(), currentLPN);
    for (int i = 0; i < ui->lpnQuantitySpinBox->value(); i++){
        status = printLabel(settings.value("MainSettings/printCommand").toString(), lpnString);
        if ( status != 0 ) break;
        if (settings.value("MainSettings/lpnBatchMode").toBool() == true){
            currentLPN++;
            lpnString = Utils::lpnPrefix(prefix, settings.value("MainSettings/lpnPadding").toInt(), currentLPN);
        }
    }
    qInfo() << "Status:" << QString("%1").arg(QString::number(status));
    if (status == 0){
        if (settings.value("MainSettings/copyClipboard").toBool()) clipboard->setText(lpnString);
        QVariantMap lpnMap = settings.value("MainSettings/lpnMap").toMap();
        lpnMap.remove(prefix);
        if (settings.value("MainSettings/lpnBatchMode").toBool() == true){
            lpnMap.insert(prefix, currentLPN);
        } else {
            lpnMap.insert(prefix, ++currentLPN);
        }
        settings.setValue("MainSettings/lpnMap", lpnMap);
        //settings.sync();
        updateUi();
    } else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error!");
        msgBox.setText("Print failed: Errno " + QString::number(status));
        msgBox.setModal(true);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
    ui->printLPNButton->setEnabled(true);
}

void MainWindow::on_skuLineEdit_returnPressed()
{
    emit on_printSKUButton_released();
}

void MainWindow::on_printSKUButton_released()
{
//    ui->printSKUButton->setEnabled(false);
//    QSettings settings;
//    for (int i = 0; i < ui->skuQuantitySpinBox->value(); i++){
//        printLabel(settings.value("MainSettings/printCommand").toString(), ui->skuLineEdit->text());
//    }
//    ui->printSKUButton->setEnabled(true);
    QSettings settings;
    QString host = settings.value("MainSettings/printServer").toString();
    quint64 port = settings.value("MainSettings/listenPort").toInt();
    lClient->sendData(host, port, "Test Data");
}

void MainWindow::on_textLineEdit_returnPressed()
{
    emit on_printTextButton_released();
}

void MainWindow::on_printTextButton_released()
{
    ui->printTextButton->setEnabled(false);
    QSettings settings;
    for (int i = 0; i < ui->textQuantitySpinBox->value(); i++){
        printLabel(settings.value("MainSettings/printCommand").toString(), ui->textLineEdit->text());
    }
    ui->printTextButton->setEnabled(true);
}

void MainWindow::on_printSalvageButton_released()
{
    ui->printSalvageButton->setEnabled(false);
    QSettings settings;
    printLabel(settings.value("MainSettings/printCommand").toString(), settings.value("MainSettings/salvageLabel").toString());
    ui->printSalvageButton->setEnabled(true);
}

void MainWindow::on_lpnQuantitySpinBox_valueChanged(int qty)
{
    QSettings settings;
    QVariantList printQuantity = settings.value("UI/printQuantity").toList();
    printQuantity.replace(0, qty);
    settings.setValue("UI/printQuantity", printQuantity);
}

void MainWindow::on_skuQuantitySpinBox_valueChanged(int qty)
{
    QSettings settings;
    QVariantList printQuantity = settings.value("UI/printQuantity").toList();
    printQuantity.replace(1, qty);
    settings.setValue("UI/printQuantity", printQuantity);
}

void MainWindow::on_textQuantitySpinBox_valueChanged(int qty)
{
    QSettings settings;
    QVariantList printQuantity = settings.value("UI/printQuantity").toList();
    printQuantity.replace(2, qty);
    settings.setValue("UI/printQuantity", printQuantity);
}

void MainWindow::on_reprintLPNButton_released()
{
    QSettings settings;
    QString prefix = settings.value("MainSettings/currentPrefix").toString();
    int prevLPN = Utils::getLPN(prefix)-1;
    QString lpnString = Utils::lpnPrefix(prefix, settings.value("MainSettings/lpnPadding").toInt(), prevLPN);
    lpnString.append(QString::number(prevLPN));
    ui->reprintLPNButton->setEnabled(false);
    for (int i = 0; i < ui->lpnQuantitySpinBox->value(); i++){
        printLabel(settings.value("MainSettings/printCommand").toString(), lpnString);
    }
    ui->reprintLPNButton->setEnabled(true);
}

void MainWindow::on_wsMessageReceived(const QString message){
    ui->textLineEdit->setText(message);
    ui->printTextButton->setEnabled(false);
    QSettings settings;
    printLabel(settings.value("MainSettings/printCommand").toString(), ui->textLineEdit->text());
    ui->printTextButton->setEnabled(true);
}


