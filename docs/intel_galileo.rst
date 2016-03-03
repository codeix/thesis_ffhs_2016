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


Compile OCD Olimex
==================

Compile OpenOCD
---------------

.. code:: bash

  git clone git://git.code.sf.net/p/openocd/code openocd-code
  cd openocd-code
 ./bootstrap
 ./configure --enable-maintainer-mode --enable-legacy-ft2232_libftdi
 
 
add "adapter_khz 6000" at the of ./tcl/interface/olimex-arm-usb-ocd.cfg
 

Run OpenOCD with Intel Galileo Board
------------------------------------

.. code:: bash
 
  ./src/openocd -f ./tcl/interface/olimex-arm-usb-ocd.cfg -f ./tcl/target/quark_x10xx.cfg



