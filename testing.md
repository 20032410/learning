# 测试
### 20170717
* 在淘宝上查找mesh模块
* 知网上查找mesh,docker资料

### 20170722
> 这里是测试说明

* 搭建openwrt
* *网口编辑*
* **卡容量扩容**
* 搜索引擎[bing](https://www.bing.com)
* /dev/sdb2,252M;/dev/sdb1/,20M，利用gparted工具进行分区，先umount/dev/sdb2,然后再扩容，增加分区大小，如果出现错误，就检查修复，完成，done！
1.  修改nameserver 114.114.114.114
2.  echo ""  >> /etc/resolv.conf
3.  223.5.5.5
4.  安装luci，opkg install luci
5.  root@LEDE:/etc/init.d# ./uhttpd enable
6.  root@LEDE:/etc/init.d# ./uhttpd start
7.  安装luci后，启用中文界面
8.  0(数字), |                移到当前行的第一列
^                       移到当前行的第一个非空字符
$                       移到当前行的最后一个字符
9.  安装基础使用：openssh-sftp-server git zip usbutils luci-i18n-base-zh-cn luci-i18n-commands-zh-cn
10.  opkg install kmod-rtl8192cu

### 20170723
> 配置ip地址，route，解决br-lan与eth0之间的问题
1.  route修改,route add -net 192.168.1.0 netmask 255.255.255.0 dev eth0
route add -net 0.0.0.0/0 gateway 192.168.1.1
2.  