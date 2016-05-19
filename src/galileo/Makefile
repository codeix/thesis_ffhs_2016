obj-m  := benchmark.o
benchmark-y := ../benchmark_main.o benchmark_asm.o benchmark_bind.o

ccflags-y :=  -DGALILEO

KDIR= $(PWD)/../linux/3.8.7_x86/lib/modules/3.8.7/build

all:
	$(PWD)/../generator.py galileo
	make ARCH=x86 -C $(KDIR) M=$(PWD)  modules

clean:
	make ARCH=x86 -C $(KDIR) M=$(PWD)  clean

