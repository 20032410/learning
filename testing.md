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
5.  将wan1的接口更改为wan口即可,brctl show
6.  root@LEDE:/etc/config# brctl show
bridge name	bridge id		STP enabled	interfaces
br-wan		7fff.b827ebf7b391	no		eth0
							wlan1
7.  注销firewall里注册的端口信息，再保存；浏览器里http://192.168.1.130即可再重新获取防火墙信息
8.  lede,github,source,source/target/linux/generic/patches-4.4/030-6-ch9200-use-skb_cow_head-to-deal-with-cloned-skbs.patch
9.  尝试安装有线网卡；以及科**学* *上网
10.  Mesh Point
Mesh Point （802.11s） 仅mac80211 驱动支持，需要安装iw包来建立mesh link。Openwrt创建mshN mesh point接口，配置举例：
configwifi-device      "wlan0"
    option type            "mac80211"
    option channel      "5"
configwifi-iface
    option device       "wlan0"
    option network     lan
    option mode         "mesh"
    option mesh_id     "OpenWrt"
11.  按照需求，安装以下软件包：

基础使用：openssh-sftp-server git zip usbutils luci-i18n-base-zh-cn luci-i18n-commands-zh-cn
无线网卡: kmod-rt2500-usb kmod-rt2800-lib kmod-rt2800-usb kmod-rt2x00-lib kmod-rt2x00-usb kmod-rt73-usb kmod-rtl8187 kmod-rtl8192c-common kmod-rtl8192cu   kmod-rtlwifi-usb kmod-rtlwifi wireless-tools kmod-lib80211 kmod-net-rtl8188eu kmod-net-rtl8192su kmod-mac80211 kmod-ath9k-htc kmod-ath9k-common hostapd-utils hostapd fstools wpa-supplicant-p2p wpa-supplicant wpa-cli wpad-mesh wpad-mini wpad wpan-tools
以太网卡: kmod-usb-core kmod-usb-net-asix-ax88179 kmod-usb-net-asix   kmod-usb-net-cdc-eem kmod-usb-net-cdc-ether kmod-usb-net-cdc-mbim kmod-usb-net-cdc-ncm   kmod-usb-net-cdc-subset kmod-usb-net-dm9601-ether kmod-usb-net-hso kmod-usb-net-huawei-cdc-ncm kmod-usb-net-ipheth kmod-usb-net-kalmia kmod-usb-net-kaweth kmod-usb-net-mcs7830 kmod-usb-net-pegasus kmod-usb-net-qmi-wwan kmod-usb-net-rndis
kmod-usb-net-sierrawireless kmod-usb-net-smsc95xx kmod-usb-net

12.  乐扩USB2.0有线网卡 USB转RJ45，网络适配器MCS7830芯片
13.  UNITEK Y-1466 USB百兆网卡（芯片应该是ASIX AX88772C） x1
14.  USB网卡作为WAN口，从现有路由器自动获取IP。
自带网卡作为LAN口，网段192.168.2.0/24设置IP 192.168.2.1，DHCP IP派发范围192.168.2.100~192.168.2.249
无线网卡与LAN属同一网段，DHCP派发范围相同。
15.  安装USB网卡驱动：opkg install kmod-usb-net-asix
16.  下载镜像，这个lede好像是openwrt的一个分支，openwrt本身还没有支持pi3，https://downloads.lede-project.org/snapshots/targets/brcm2708/bcm2710/lede-brcm2708-bcm2710-rpi-3-ext4-sdcard.img
17.  修改/etc/config/network
	
``` 
config interface 'loopback'
        option ifname 'lo'
        option proto 'static'
        option ipaddr '127.0.0.1'
        option netmask '255.0.0.0'

config globals 'globals'
        option ula_prefix 'fd11:8629:b448::/48'

config interface 'lan'
         option type 'bridge'
  #       option ifname 'eth0'
        option proto 'static'
        option ipaddr '192.168.1.1'
        option netmask '255.255.255.0'
        option ip6assign '60'

config interface wan
        option proto dhcp
        option ifname eth0
      
````

18.  修改wireless

````
config wifi-device radio0
        option type     mac80211
        option channel  11
        option hwmode   11g
        option path     'platform/soc/3f300000.mmc/mmc_host/mmc1/mmc1:0001/mmc1:0001:1'
        option htmode   HT20
        # REMOVE THIS LINE TO ENABLE WIFI:
        option disabled 0

config wifi-iface
        option device   radio0
        option network  lan
        option mode     ap
        option ssid     OpenWrt_RPI3
        option encryption psk2
        option key      yourwifikey
````
19.  opkg install luci
/etc/init.d/uhttpd start
/etc/init.d/uhttpd enable
20.  允许通过wan连接ssh

/etc/config/firewal

````
#open ssh on wan interface
config rule                
        option src              wan
        option dest_port        22
        option target           ACCEPT     
        option proto  
````
21.  添加命令

````
# opkg install kmod-usb2 kmod-usb-ohci kmod-usb-ohci kmod-ath9k-common kmod-ath9k-htc hostapd

````
22.  修改/etc/config/wireless

````
config wifi-device radio0
        option type     mac80211
        option channel  11
        option hwmode   11g
        option path     'platform/soc/3f300000.mmc/mmc_host/mmc1/mmc1:0001/mmc1:0001:1'
        option htmode   HT20
        # REMOVE THIS LINE TO ENABLE WIFI:
        option disabled 0
  
config wifi-iface
        option device   radio0
        option network  lan
        option mode     ap
        option ssid     OpenWrt_RPI3
        option encryption psk2
        option key      yourwifikey
````


### 20170724
1. Bus 001 Device 011: ID 1a86:e092 QinHeng Electronics,CH9200 USB Ethernet

### 201725
1. 使用wpa_supplicant连接使用wlan0
2. 一：所用命令

dmesg | grep firmware（看看有没有来自无线网卡的固件请求）

iw：

     iw dev(查找无线网卡口)

     iw wls1 link(查看wls1网口无线网络连接情况)

     iw wls1 scan | grep SSID(查看wls1网口可连接的wifi)

ip：

     ip link set wls1 up(将无线网口wls1开启)

     ip link show wls1(显示无线网口wls1连接情况)

     ip addr  show wls1(显示分配的ip地址，特别适用于查看是否成功地通过dhcp自动获取了ip地址) 

wpa_supplican:

     wpa_supplicant -B -i wlp3s0 -c <(wpa_passphrase "ssid" "psk") (连接无线网ssid，密码psk)

dhclient:

     dhclient wls1(为wls1分配ip地址)

如需使用上述命令，只需将wls1直接更换成自己网口就


        查看是否需要安装固件

        大多无线网卡还需要固件。内核一般会自动探测并加载两者，如果您得到类似 SIOCSIFFLAGS: No such file or directory 的输出，意味着您得手动加载固件。若不确定，用 dmesg 查询内核日志，看看有没有来自无线网卡的固件请求。比如您有 Intel 芯片组，输出大概是这样：
        # dmesg | grep firmware
        firmware: requesting iwlwifi-5000-1.ucode
        若无输出，表明系统的无线芯片不需要固件。

        查看无线网口：

        #iw dev(interface后面即为无线网口号)

        激活无线网络接口：
        # ip link set wls1 up 
        为了检验接口是否激活成功，您可以查看以下命令的输出：
        # ip link show wls1
        3: wls1: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc mq state DOWN mode DORMANT group default qlen 1000 link/ether 00:11:22:33:44:55 brd ff:ff:ff:ff:ff:ff 
        <BROADCAST,MULTICAST,UP,LOWER_UP> 中的UP 表明该接口激活成功，后面的 state DOWN 无关紧要。

        查看无线网络连接情况：

        #iw wls1 link
        刚开始应该会显示无连接

        扫描可连接的wifi
        #iw wls1 scan | grep SSID

        扫描可用的网络

        连接指定的SSID
        # wpa_supplicant -B -i wlp3s0 -c <(wpa_passphrase "ssid" "psk") 
        将ssid 替换为实际的网络名称，psk 替换为无线密码，请保留引号。

        用dhcp 获得 IP 分配：
        # dhclient wlp3s0 

        测试是否成功地从路由器获取了ip(重要)

        #ip addr  show wls1

        如果分配有ip，即可上网，也可以有ping直接测试                .conf3. 
3. 配置/etc/etc/wpa_supplicant/etc/wpa_supplicant.conf
4. wpa_supplicant -B -i wlan0 -c /etc/wpa_supplicant/wpa_supplicant.conf

````
root@LEDE:/etc/wpa_supplicant# cat wpa_supplicant.conf
ctrl_interface=/var/run/wpa_supplicant
update_config=1
country=CN

network={
	ssid="AndroidAPli078"
	psk="12345678"
	key_mgmt=WPA-PSK
	disabled=1
}
````
5. 在luci配置界面上，进行无线搜索，在指定的wifi下连接

### 20170726
1. 将openwrt wifi，wlan0配置为802.11s
2. upported interface modes:
		 * IBSS
		 * managed
		 * AP
		 * AP/VLAN
		 * monitor
		 * mesh point
		 * P2P-client
		 * P2P-GO
		 
3. mesh 第9频道

### 20170727
1. 配置mesh
iw phy phy0 interface add mesh0 type mesh
iw dev mesh0 set meshid mymesh
iw dev mesh0 set channel 3 HT40+
ifconfig mesh0 hw ether 00:1C:11:11:11:11
ifconfig mesh0 up

设置iw mesh的网络接口及mp模式
2. iw dev wlan1 interface add mesh_iface type mp
3. ifconfig -a | grep mesh_iface
4. iw dev mesh_iface set channel 1
5. iw dev mesh_iface set meshid mymesh
6. ifconfig mesh_iface 192.168.2.140
7. ifconfig mesh_iface 192.168.2.130

config wifi-device 'radio1'
	option type 'mac80211'
	option hwmode '11g'
	option path 'platform/soc/3f980000.usb/usb1/1-1/1-1.4/1-1.4:1.0'
	option htmode 'HT20'
	option country '00'
	option channel '1'

config wifi-iface 'default_radio1'
	option device 'radio1'
	option network 'lan'
	option mode 'ap'
	option ssid 'LEDE_li130'
	option encryption 'psk2'
	option key 'li123456'
	option wps_pushbutton '0'
	
9. config wifi-device 'radio1'
	option type 'mac80211'
	option hwmode '11g'
	option path 'platform/soc/3f980000.usb/usb1/1-1/1-1.4/1-1.4:1.0'
	option htmode 'HT20'
	option country '00'
	option channel '1'

config wifi-iface 'default_radio1'
	option device 'radio1'
	option network 'lan'
	option ssid 'LEDE_li130'
	option key 'li123456'
	option mode 'mesh'
	option encryption 'none'

10. mesh
	 #!/bin/bash

iw dev wlan1 interface add mesh_iface type mp
iw dev mesh_iface set channel 1
iw dev mesh_iface set meshid mymesh
ifconfig mesh_iface 192.168.2.130

11. 开启网卡监听模式
ifconfig wlan2(网卡) down
iwconfig wlan2 mode monitor( 设置为监听)
ifconfig wlan2 up(开启网卡)
iwconfig wlan2（查看信息）

如果有线连接不可用, 需要使用这个功能，就要创建两个独立的虚拟网络接口。 可以通过如下方式为wlan0 创建负责网络连接的 wlan0_sta 和负责热点的 wlan0_ap. 两个虚拟网卡具有不同的 MAC 地址。
iw dev wlan0 interface add wlan0_sta type managed addr 12:34:56:78:ab:cd  
iw dev wlan0 interface add wlan0_ap  type managed addr 12:34:56:78:ab:ce

可以用 macchanger 创建随机 MAC 地址。
ip link set dev wlan0_ap up
网络配置
有两种基本的实现方法：
网桥: 在电脑上搭一个网桥 （无线客户端就可以像电脑一样访问同一个网络接口和同一个子网）
NAT: 通过 IP 转发/伪装和 DHCP 服务 （无线客户端会专门使用一个子网, 数据进出这个子网是被网络地址转换的(NAT-ted) —— 就像是连接在你数字用户回路(DSL)或铜轴线(Cabel)调制解调器上的一个普通的无线路由器一样)

### 20170730
1. $ ifconfig wlan0 down
$ iw dev wlan0 del
$ iw phy phy0 interface add wlan0 type __ap
$ ifconfig wlan0 up

2. iw phy phy1 interface add mesh0 type mesh
3. iw：

     iw dev(查找无线网卡口)

     iw wls1 link(查看wls1网口无线网络连接情况)

     iw wls1 scan | grep SSID(查看wls1网口可连接的wifi)

ip：

     ip link set wls1 up(将无线网口wls1开启)

     ip link show wls1(显示无线网口wls1连接情况)

     ip addr  show wls1(显示分配的ip地址，特别适用于查看是否成功地通过dhcp自动获取了ip地址) 

wpa_supplican:

     wpa_supplicant -B -i wlp3s0 -c <(wpa_passphrase "ssid" "psk") (连接无线网ssid，密码psk)

dhclient:

     dhclient wls1(为wls1分配ip地址)

如需使用上述命令，只需将wls1直接更换成自己网口就行了
iw phy phy0 interface add moni0 type monitor
iw phy phy0 interface add wlan10 type managed
iw dev wlan0 interface add fish0 type monitor flags none
如何在mesh的基础上桥接网络？
Mesh Portal (MPP) 
To bring up an MPP we need to setup up a bridge between a mesh interface and, for example, an Ethernet interface.
1. Bring up a mesh interface as described in the "Testing" section above.
mpp$ iw dev wlan0 interface add mesh type mp mesh_id ${MESH_ID}
mpp$ ifconfig mesh up
2. Add this new interface and your ethN interface to a new bridge:
mpp$ brctl addbr br0
mpp$ brctl stp br0 off
mpp$ brctl addif br0 eth1
mpp$ brctl addif br0 mesh
mpp$ ifconfig mesh down
mpp$ ifconfig eth1 down
mpp$ ifconfig mesh 0.0.0.0 up
mpp$ ifconfig eth1 0.0.0.0 up
mpp$ ifconfig br0 ${MESH_IP}
如何设置桥接
root@bridge:~> brctl addbr br0
root@bridge:~> brctl stp br0 off
root@bridge:~> brctl addif br0 eth0
root@bridge:~> brctl addif br0 eth1
root@bridge:~> ifconfig eth0 down
root@bridge:~> ifconfig eth1 down
root@bridge:~> ifconfig eth0 0.0.0.0 up
root@bridge:~> ifconfig eth1 0.0.0.0 up
root@bridge:~> ifconfig br0 10.0.3.129        

4. hostapd: 用于建立AP的用户空间程序（hostapd is a user space daemon for access point and authentication servers）
iw: 一个基于nl80211的命令行控制程序（iw is a new nl80211 based CLI configuration utility for wireless devices. It supports almost all new drivers that have been added to the kernel recently）
iwconfig / iwlist / iwpriv: 一系列基于Linux Wireless Extension的无线配置工具（Wireless tools for Linux is a package of Linux commands (simple text-based utilities/tools) intended to support and facilitate the configuration of wireless devices using the Linux Wireless Extension.）

5.
iw dev wlan1 del
iw phy phy1 interface add mesh0 type mesh
iw dev mesh0 set meshid mymesh
iw dev mesh0 set channel 3 HT40+
ifconfig mesh0 hw ether 00:1C:11:11:11:11
ifconfig mesh0 up
ifconfig mesh0 192.168.2.140
iw dev mesh station dump

iw dev wlan1 del
iw phy phy1 interface add mesh0 type mesh
iw dev mesh0 set meshid mymesh
iw dev mesh0 set channel 1
ifconfig mesh0 hw ether 00:1C:11:11:11:12
ifconfig mesh0 up
ifconfig mesh0 192.168.2.140

6. 设置桥接
如何设置桥接
root@bridge:~> brctl addbr br0
root@bridge:~> brctl stp br0 off
root@bridge:~> brctl addif br0 eth0
root@bridge:~> brctl addif br0 eth1
root@bridge:~> ifconfig eth0 down
root@bridge:~> ifconfig eth1 down
root@bridge:~> ifconfig eth0 0.0.0.0 up
root@bridge:~> ifconfig eth1 0.0.0.0 up
root@bridge:~> ifconfig br0 10.0.3.129  

7. 通过修改iptables来实现网卡之间ip数据流交换
		#!/bin/bash
		#edit by lielieli 20170730
iptables -F
iptables -X
iptables -t nat -A POSTROUTING -o mesh0 -j MASQUERADE
iptables -A FORWARD -i mesh0 -o br-lan -j ACCEPT
iptables -A FORWARD -i br-lan -o mesh0 -j ACCEPT
iptables -L -n
printf "done\n"

8. d单个Wi-Fi设备同时作为无线客户端和AP
	Wiphy phy1
...
        valid interface combinations:
                 * #{ managed } <= 2048, #{ AP, mesh point } <= 8, #{ P2P-client, P2P-GO } <= 1,
                   total <= 2048, #channels <= 1, STA/AP BI must match
...

9. 约束#channels <= 1说明软件热点必须和 Wi-fi 客户端连接处于同一信道。 参见channel里的hostapd.conf设置。
如果有线连接不可用, 需要使用这个功能，就要创建两个独立的虚拟网络接口。 可以通过如下方式为wlan0 创建负责网络连接的 wlan0_sta 和负责热点的 wlan0_ap. 两个虚拟网卡具有不同的 MAC 地址。
	 iw dev wlan0 interface add wlan0_sta type managed addr 12:34:56:78:ab:cd 
	 iw dev wlan0 interface add wlan0_ap  type managed addr 12:34:56:78:ab:ce

### 20170731

1. 启用 NAT
iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
iptables -A FORWARD -m conntrack --ctstate RELATED,ESTABLISHED -j ACCEPT
iptables -A FORWARD -i wlan0 -o eth0 -j ACCEPT
2. 导出 NAT 规则至文件
iptables-save > /etc/iptables/ap.rules
3. 重启保存
ifconfig wlan0 192.168.0.1/24
systemctl start dnsmasq
iptables-restore < /etc/iptables/ap.rules
sysctl net.ipv4.ip_forward=1
systemctl start hostapd
4.

### 20170801
ifconfig wlan0 down
ifconfig wlan0 10.0.0.1 netmask 255.255.255.0 up
iwconfig wlan0 power off
service dnsmasq restart
hostapd -B /etc/hostapd/hostapd.conf & > /dev/null 2>&1
sudo iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE  
sudo iptables -A FORWARD -i eth0 -o wlan0 -m state --state RELATED,ESTABLISHED -j ACCEPT  
sudo iptables -A FORWARD -i wlan0 -o eth0 -j ACCEPT

### 20170803
1. Android应用安装涉及到如下几个目录：
system/app系统自带的应用程序，无法删除。
data/app用户程序安装的目录，有删除权限。安装时把apk文件复制到此目录。
data/data存放应用程序的数据。
data/dalvik-cache将apk中的dex文件安装到dalvik-cache目录下(dex文件是dalvik虚拟机的可执行文件,其大小约为原始apk文件大小的四分之一)。

2. 网络基本流程介绍
	* 明确需求
	* 现场工勘
	* 网络方案设计
	+ 售前测试、售前测试报告、无线地勘报告、走线，投标文件
	+ 施工队
	




