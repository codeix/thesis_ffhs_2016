<<<<<<< HEAD
/* benchmark_main.c -- Benchmark
 *
 * Copyright (C) 2016 copyright Samuel Riolo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */


=======
>>>>>>> 68e59547ab97f84e6d3e58ae8d285bb30d059e8c
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

#include <linux/fs.h>       // for basic filesystem
#include <linux/proc_fs.h>  // for the proc filesystem
#include <linux/seq_file.h> // for sequence files
<<<<<<< HEAD

#include "benchmark_asm.h"
#include "benchmark_bind.h"

#define PROC_DIR "benchmark"
=======
#include <linux/jiffies.h>  // for jiffies

#include "benchmark_cases.h"

#define PROC_DIR "benchmark"
#define TEST 85
>>>>>>> 68e59547ab97f84e6d3e58ae8d285bb30d059e8c

static struct proc_dir_entry* benchmark_file;
static struct proc_dir_entry* benchmark_parent;

<<<<<<< HEAD

static int benchmark_open(struct inode* inode, struct file* file)
{
    return single_open(file, BENCHMARK_SHOW_BIND[(int)PDE(inode)->data], benchmark_parent);
=======
struct point {
   int x;
   int y;
};


static void *benchmark_start(struct seq_file *p, loff_t *pos)
{
        struct point *my = p->private;
        return 777;
}

static void *benchmark_next(struct seq_file *p, void *v, loff_t *pos)
{
        ++*pos;
        return 555;
}

static void benchmark_stop(struct seq_file *p, void *v)
{
}


static int benchmark_show(struct seq_file* m, void* v)
{

    // benchmark_handler * fh;
    // fh=PDE_DATA(file_inode(seq_file));

    // benchmark_handler* bla = (benchmark_handler *)m->private;
    unsigned long long start_jif = get_jiffies_64();
    // (*(bla[0]))();
    benchmark_add_simple();

    struct point *my = m->private;
    struct point *myv = v;

    unsigned long long exec_jif = get_jiffies_64() - start_jif;
    seq_printf(m, "%llu\n%i\n%i\n", (unsigned long long)exec_jif, m->private, myv);
    return 0;
}

static const struct seq_operations benchmark_seq_ops = {
        .start = benchmark_start,
        .next = benchmark_next,
        .stop = benchmark_stop,
        .show = benchmark_show,
};

static int benchmark_open(struct inode* inode, struct file* file)
{
    struct point my_point = { 3, 7 };
//    printk(KERN_ERR "something went wrong, return code mypoint: %d\n", file);
//    printk(KERN_ERR "something went wrong, return code poi: %d\n", &(PDE(inode)->data));
    // int res = single_open(file, benchmark_show, PDE(inode)->data);
    // return res;

        //int res = seq_open_private(file, &benchmark_seq_ops, sizeof(int));
                

	//((struct seq_file *)file->private_data)->private = 96666;
        //return res;


    return single_open(file, benchmark_show, &my_point);
    //ret = ret + seq_open_private(file, file->private_data, sizeof(int));
    //((struct seq_file *)file->private_data).private = 9666;
    //return ret;
    //return ret;
}



static int benchmark_release(struct inode* inode, struct file* file)
{

    return single_release(inode, file);
>>>>>>> 68e59547ab97f84e6d3e58ae8d285bb30d059e8c
}

static const struct file_operations benchmark_fops = {
    .owner = THIS_MODULE,
    .open = benchmark_open,
    .read = seq_read,
    .llseek = seq_lseek,
    .release = single_release,
};

static int __init benchmark_init(void)
{
<<<<<<< HEAD
    int i;
    benchmark_parent = proc_mkdir(PROC_DIR, NULL);
    for(i=0; i < BENCHMARK_SHOW_LENGTH; i++){
        benchmark_file = proc_create_data(
            BENCHMARK_SHOW_NAME[i], 0, benchmark_parent,
            &benchmark_fops, (void *)i);
    }
=======
    benchmark_parent = proc_mkdir(PROC_DIR, NULL);
    benchmark_handler benchmark_func = BENCHMARK_FUNCTIONS;
    // benchmark_file = proc_create_data("benchmark", 0, benchmark_parent, &benchmark_fops, benchmark_func);

    benchmark_file = proc_create_data("benchmark", 0, benchmark_parent, &benchmark_fops, 1985);
>>>>>>> 68e59547ab97f84e6d3e58ae8d285bb30d059e8c
    if(!benchmark_file) {
        return -ENOMEM;
    }

    return 0;
}

static void __exit benchmark_exit(void)
{
<<<<<<< HEAD
    int i;
    for(i=0; i < BENCHMARK_SHOW_LENGTH; i++){
        remove_proc_entry(BENCHMARK_SHOW_NAME[i], benchmark_parent);
    }
=======
    remove_proc_entry("benchmark", benchmark_parent);
>>>>>>> 68e59547ab97f84e6d3e58ae8d285bb30d059e8c
    remove_proc_entry(PROC_DIR, NULL);
}

module_init(benchmark_init);
module_exit(benchmark_exit);

<<<<<<< HEAD
MODULE_LICENSE("MIT");
=======
MODULE_LICENSE("GPL");
>>>>>>> 68e59547ab97f84e6d3e58ae8d285bb30d059e8c
