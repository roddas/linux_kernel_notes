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


## Compiling the Kernel

Run the following command to generate a kernel configuration file based on the current configuration. This step is important to configure the kernel, which has a good chance to work correctly on your system. You will be prompted to tune the configuration to enable new features and drivers that have been added since Ubuntu snapshot the kernel from the mainline. make all will invoke make oldconfig in any case. I am showing these two steps separately just to call out the configuration file generation step.
```
make oldconfig

Another way to trim down the kernel and tailor it to your system is by using make localmodconfig. This option creates a configuration file based on the list of modules currently loaded on your system.

lsmod > /tmp/my-lsmod
make LSMOD=/tmp/my-lsmod localmodconfig

Once this step is complete, it is time to compile the kernel. Using the -j option helps the compiles go faster. The -j option specifies the number of jobs (make commands) to run simultaneously:

make -j3 all
```

cp /boot/<config-5.0.0-21-generic> .config
```
