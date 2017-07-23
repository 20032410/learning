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
2.  -net，表示后面接的路由为一个网段；
-host，表示后面接的为连接到单台主机的路由；
Netmask，和网段有关，能设置 netmask 决定网段的大小；
Gw，gateway的简写，后续接的是 IP 的数值，和 dev 不同；
Dev，只是要指定由哪一块网卡联机出去时使用这个设置，后面接eth0 等。
3.  //添加到主机的路由
route add –host 192.168.1.11 dev eth0
route add –host 192.168.1.12 gw 192.168.1.1
//添加到网络的路由
route add –net 192.168.1.11  netmask 255.255.255.0 eth0
route add –net 192.168.1.11  netmask 255.255.255.0 gw 192.168.1.1
route add –net 192.168.1.0/24 eth1
//添加默认网关
route add default gw 192.168.2.1
//删除路由
route del –host 192.168.1.11 dev eth0
4.  U Up表示此路由当前为启动状态
H Host，表示此网关为一主机
G Gateway，表示此网关为一路由器
R Reinstate Route，使用动态路由重新初始化的路由
D Dynamically,此路由是动态性地写入
M Modified，此路由是由路由守护程序或导向器动态修改
! 表示此路由当前为关闭状态
5.  