obj-m  := benchmark.o
benchmark-y := benchmark_main.o benchmark_asm.o benchmark_bind.o

KDIR= $(HOME)/3.8.7/lib/modules/3.8.7/build

all:
	$(PWD)/generator.py
	make ARCH=x86 -C $(KDIR) M=$(PWD) modules

clean:
	make ARCH=x86 -C $(KDIR) M=$(PWD) clean

