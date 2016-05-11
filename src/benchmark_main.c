/* benchmark_main.c -- Benchmark
 *
 * Copyright (C) 2016 copyright Samuel Riolo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */


#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

#include <linux/fs.h>       // for basic filesystem
#include <linux/proc_fs.h>  // for the proc filesystem
#include <linux/seq_file.h> // for sequence files

#ifdef GALILEO
#include "galileo/benchmark_asm.h"
#include "galileo/benchmark_bind.h"
#endif



#define PROC_DIR "benchmark"

static struct proc_dir_entry* benchmark_file;
static struct proc_dir_entry* benchmark_parent;


static int benchmark_open(struct inode* inode, struct file* file)
{
    return single_open(file, BENCHMARK_SHOW_BIND[(int)PDE(inode)->data], benchmark_parent);
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
    int i;
    benchmark_parent = proc_mkdir(PROC_DIR, NULL);
    for(i=0; i < BENCHMARK_SHOW_LENGTH; i++){
        benchmark_file = proc_create_data(
            BENCHMARK_SHOW_NAME[i], 0, benchmark_parent,
            &benchmark_fops, (void *)i);
    }
    if(!benchmark_file) {
        return -ENOMEM;
    }

    return 0;
}

static void __exit benchmark_exit(void)
{
    int i;
    for(i=0; i < BENCHMARK_SHOW_LENGTH; i++){
        remove_proc_entry(BENCHMARK_SHOW_NAME[i], benchmark_parent);
    }
    remove_proc_entry(PROC_DIR, NULL);
}

module_init(benchmark_init);
module_exit(benchmark_exit);

MODULE_LICENSE("MIT");
