Remote over Serial connection
=============================

Connect a 4Pin serial connector to a Intel Galileo Gen2 Board


=== ===== ======
Pin Color  Name
=== ===== ======
1   Black Ground
2   x     RTS
3   Red   x
4   Green RXI
5   White TXI
6   x     CTS
=== ===== ======


Command to open terminal
------------------------

sudo screen /dev/ttyUSB0 115200,cs8,-ixon,-ixoff

setting for galileo board:
stty 115200 cs8 -parenb -crtscts echo -F /dev/ttyS1


Prepare SD Card
---------------

Download:
https://software.intel.com/sites/landingpage/iotdk/board-boot-image.html

Copy to SD Card:
sudo dd if=iot-devkit-version-mmcblkp0.direct of=/dev/diskname bs=3M conv=fsync


