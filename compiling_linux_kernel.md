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
## Copying the Configuration for Current Kernel from /boot

Starting out with the distribution configuration file is the safest approach for the very first kernel install on any system. You can do so by copying the configuration for your current kernel from /proc/config.gz or /boot. As an example, I am running Ubuntu 19.04 and config-5.0.0-21-generic is the configuration I have in /boot on my system. Pick the latest configuration you have on your system and copy that to linux_stable/.config. In the following example, config-5.0.0-21-generic is the latest kernel configuration.

```
ls /boot
config-5.0.0-20-generic        memtest86+.bin
config-5.0.0-21-generic        memtest86+.elf
efi                            memtest86+_multiboot.bin
grub                           System.map-5.0.0-20-generic
initrd.img-5.0.0-20-generic    System.map-5.0.0-21-generic
initrd.img-5.0.0-21-generic    vmlinuz-5.0.0-20-generic
lost+found                     vmlinuz-5.0.0-21-generic

cp /boot/<config-5.0.0-21-generic> .config
```
