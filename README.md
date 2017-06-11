# Tiny210

#### 工具集介绍
    
    readelf -h / file           查看可执行文件头信息(readelf -d linuxrc | grep NEEDED)
    size                        打印相关信息
    nm                          同上
    strip                       剔除符号表
    strings                     查看文件中定义的字符串
    objcopy
    objdump -d/-D
    addr2line

#### u-boot命令

    print                       查看u-boot环境变量
    setenv/saveenv              设置/保存环境变量(setenv ipaddr 192.168.10.110)
    tftp                        (tftp 0x20008000 uImage)
    md                          
    nand erase/write/read       (nand read 0x21000000 0x100000 1024)
    bootm                       (bootm 0x20008000)
    go
    >OK

#### 启动参数
    
    root=                       根文件系统在哪个设备,设备信息(ram,NFS,flash)
    init=                       内核启动后第一个程序

    uImage(内核)                tftp 0x20008000 uImage 
    initrd.img.gz(文件系统)     tftp 0x21000000 initrd.img.gz
    setenv bootargs root=/dev/ram initrd=0x21000000,8M init=/linuxrc console=ttySAC0,115200
    bootm 0x20008000

#### NFS文件系统

    解压已有的文件系统          gunzip initrd.img.gz
    挂载到一个目录              mount -t ext4 initrd.img /home/daixiang/rootfs
    下载                        sudo apt-get install nfs-kernel-server
    配置                        sudo echo '/home/daixiang/rootfs    *(rw,sync,no_subtree_check)' > /etc/exports
    启动                        sudo /etc/init.d/nfs-sernel-server restart
    setenv bootargs root=/dev/nfs nfsroot=192.168.10.110:home/daixiang/rootfs ip=192.168.10.122 init=/linuxrc console=ttySAC0,115200

#### busybox

    make defconfig;make
    make CONFIG_PREFIX=./busybox install

    sudo apt-get install libncurses*
    make memuconfig;make

#### etc 
    fstab
    inittab                     系统启动项
    profile                     环境变量

#### Linux编译

    1. 清除原有配置与中间文件
        x86: make mrproper
        arm: make mrproper ARCH=arm

    2. 配置内核
        x86: make menuconfig
        arm: make menuconfig ARCH=arm

    3. 创建依赖
        x86: make dep
        arm: make dep ARCH=arm CROSS_COMPILE=arm-linux-

    4. 编译内核
        x86: make zbImage
        arm: make zImage ARCH=arm CROSS_COMPILE=arm-linux-

#### MMU(地址转换)
        
                                    线性地址
                31      22          21      12          11      0
                DIRECTORY           TABLE               OFFSET
                    |                 |                    |
                    |                 |                    |
                    |                 |                    页
                    |                 |      页表基地址+线性地址低12位(12位刚好寻址4K)定位具体物理内存
                    |                 |                    ^
                    |            页表(数组)                |
                    |   页目录基地址+线性地址中间10位------|
                    |                 ^
              页目录(数组)            |
    cr3(页目录基地址)+线性地址高10位--|

    每一个进程都一个页目录保存在cr3寄存器中
            

    2.4内核三级分页机制,某一级设0即可兼容二级分页机制 
    2.6内核四级分页机制,某一级设0即可兼容三级分页机制



