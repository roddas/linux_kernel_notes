# Compiling the Linux Kernel

## Cloning the Stable Kernel Git

Start by cloning the stable kernel git, building and installing the latest stable kernel. 
The stable cloning step below will create a new directory named linux-stable and populate it with the sources. 
The stable repository has several branches going back to *linux-2.6.11.y*. 
Let’s start with the latest stable release branch. 
As of this writing (April 2021), it is linux-5.12.y, which is used in the following example. 
You can find the latest stable or a recent active kernel release.
```
git clone git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git linux_stable
cd linux_stable
git branch -a | grep linux-5
    remotes/origin/linux-5.12.y
    remotes/origin/linux-5.11.y
    remotes/origin/linux-5.10.y

​git checkout linux-5.12.y

```

