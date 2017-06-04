# Tiny210

#### 工具集介绍
    
    readelf -h / file           查看可执行文件头信息
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

#### 启动参数
    
    root=                       根文件系统在哪个设备,设备信息(ram,NFS,flash)
    init=                       内核启动后第一个程序

    uImage(内核)                tftp 0x20008000 uImage 
    initrd.img.gz(文件系统)     tftp 0x21000000 initrd.img.gz
    setenv bootargs root=/dev/ram initrd=0x21000000,8M init=/linuxrc console=ttySAC0,115200
    bootm 0x20008000
