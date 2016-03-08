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
#include <linux/jiffies.h>  // for jiffies

#include "benchmark_asm.h"
#include "benchmark_bind.h"

#define PROC_DIR "benchmark"

static struct proc_dir_entry* benchmark_file;
static struct proc_dir_entry* benchmark_parent;

int benchmark_show(struct seq_file* m, void* v)
{
    unsigned long long start_jif = get_jiffies_64();
    unsigned long long exec_jif;

    benchmark_add_zero();

    exec_jif = get_jiffies_64() - start_jif;
    seq_printf(m, "%llu\n", (unsigned long long)exec_jif);
    return 0;
}

static int benchmark_open(struct inode* inode, struct file* file)
{
    return single_open(file, BENCHMARK_SHOW_BIND, benchmark_parent);
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
    benchmark_parent = proc_mkdir(PROC_DIR, NULL);
    benchmark_file = proc_create("benchmark", 0, benchmark_parent, &benchmark_fops);

    if(!benchmark_file) {
        return -ENOMEM;
    }

    return 0;
}

static void __exit benchmark_exit(void)
{
    remove_proc_entry("benchmark", benchmark_parent);
    remove_proc_entry(PROC_DIR, NULL);
}

module_init(benchmark_init);
module_exit(benchmark_exit);

MODULE_LICENSE("MIT");
