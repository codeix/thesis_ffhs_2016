obj-m  := benchmark.o
benchmark-y := ../benchmark_main.o benchmark_asm.o benchmark_bind.o

ccflags-y :=  -DRASPBERRY


KDIR= $(HOME)/3.18.16/lib/modules/3.18.16/build

all:
	$(PWD)/../generator.py raspberry
	make ARCH=arm -C $(KDIR) M=$(PWD) CROSS_COMPILE=arm-linux-gnueabihf- modules

clean:
	make ARCH=arm -C $(KDIR) M=$(PWD)  clean

