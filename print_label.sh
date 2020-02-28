#!/bin/bash
xPad=30
yPad=30
textSize=55
barcodeSize=85
if [ "$#" -ne 2 ];
then printer="Zebra_Technologies_ZTC_ZP_500_"; label="$1";
else printer="$1"; label="$2";
fi
/bin/lpr -P "$printer" -o raw <<< "^XA^CF0,$textSize^FO$xPad,$yPad^FD$label^FS^FO$xPad,$(($textSize+$yPad))^BY2^BCN,$barcodeSize,N,N,A^FD$label^FS^XZ"
echo $?

