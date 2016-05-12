obj-m  := benchmark.o
benchmark-y := ../benchmark_main.o benchmark_asm.o benchmark_bind.o

ccflags-y :=  -DRASPBERRY

KDIR= $(HOME)/Downloads/linux-rpi-3.18.y/

all:
	$(PWD)/../generator.py raspberry
	make ARCH=arm -C $(KDIR) M=$(PWD) CROSS_COMPILE=arm-linux-gnueabihf- SUBDIRS=$(PWD) modules

clean:
	make ARCH=arm -C $(KDIR) M=$(PWD) CROSS_COMPILE=arm-linux-gnueabihf- SUBDIRS=$(PWD) clean

