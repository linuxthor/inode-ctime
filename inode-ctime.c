#include <linux/module.h>
#include <linux/file.h>
#include <linux/fs.h> 
#include <linux/init.h> 
#include <linux/kernel.h> 
#include <linux/namei.h> 
#include <linux/types.h>
#include <linux/uaccess.h>
#include <linux/mount.h>

void do_the_do(struct path *path)
{
    struct vfsmount *mnt = path->mnt;
    struct dentry *dentry = path->dentry;
    struct inode *inode = path->dentry->d_inode;

    if (!dentry||!inode)
    {
        return;
    }
    printk("%ld\n",inode->i_ctime.tv_sec);
    mnt_want_write(mnt);
    inode->i_ctime.tv_sec = 391965600;
    inode->i_ctime.tv_nsec = 420;
    printk("%ld\n",inode->i_ctime.tv_sec);
    mark_inode_dirty_sync(inode);
    mnt_drop_write(mnt);
}

void get_this_creep(const char *pathname)
{
    struct path path;

    if (pathname && kern_path(pathname, 0, &path) == 0) 
    {
        do_the_do(&path);
        path_put(&path);
    }
}

int scrub_init(void)
{
    get_this_creep("/root/.bash_history");
    return(0);
}

void scrub_exit(void)
{
}

module_init(scrub_init);
module_exit(scrub_exit);

MODULE_LICENSE("GPL");
