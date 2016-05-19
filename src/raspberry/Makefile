obj-m  := benchmark.o
benchmark-y := ../benchmark_main.o benchmark_asm.o benchmark_bind.o

ccflags-y :=  -DRASPBERRY

KDIR= $(PWD)/../linux/linux-rpi-3.18.y/
GCC_ARM= $(PWD)/../linux/tools//arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/bin/arm-linux-gnueabihf-

all:
	$(PWD)/../generator.py raspberry
	make ARCH=arm -C $(KDIR) M=$(PWD) CROSS_COMPILE=$(GCC_ARM) SUBDIRS=$(PWD) modules

clean:
	make ARCH=arm -C $(KDIR) M=$(PWD) CROSS_COMPILE=$(GCC_ARM)- SUBDIRS=$(PWD) clean

