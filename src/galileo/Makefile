obj-m  := bm_mod.o
bm_mod-y := benchmark.o benchmark_cases.o

KDIR= /home/sriolo/3.8.7/lib/modules/3.8.7/build

all:
	make ARCH=x86 -C $(KDIR) M=$(PWD) modules

clean:
	make ARCH=x86 -C $(KDIR) M=$(PWD) clean

