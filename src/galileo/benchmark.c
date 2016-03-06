 #include <linux/module.h>
 #include <linux/init.h>
 #include <linux/kernel.h>

 #include <linux/fs.h>		// for basic filesystem
 #include <linux/proc_fs.h>	// for the proc filesystem
 #include <linux/seq_file.h>	// for sequence files
 #include <linux/jiffies.h>	// for jiffies

 #include "benchmark_cases.h"

 static struct proc_dir_entry* benchmark_file;

 static int 
 benchmark_show(struct seq_file *m, void *v)
 {
   unsigned long long start_jif =  get_jiffies_64();

   benchmark_add_simple();

   unsigned long long exec_jif =  get_jiffies_64() - start_jif;   
   seq_printf(m, "%llu",
       (unsigned long long) exec_jif);
   return 0;
 }

 static int
 benchmark_open(struct inode *inode, struct file *file)
 {
     return single_open(file, benchmark_show, NULL);
 }

 static const struct file_operations benchmark_fops = {
     .owner	= THIS_MODULE,
     .open	= benchmark_open,
     .read	= seq_read,
     .llseek	= seq_lseek,
     .release	= single_release,
 };

 static int __init 
 benchmark_init(void)
 {
     benchmark_file = proc_create("benchmark", 0, NULL, &benchmark_fops);

     if (!benchmark_file) {
         return -ENOMEM;
     }

     return 0;
 }

 static void __exit
 benchmark_exit(void)
 {
     remove_proc_entry("benchmark", NULL);
 }

 module_init(benchmark_init);
 module_exit(benchmark_exit);

 MODULE_LICENSE("GPL"); 
