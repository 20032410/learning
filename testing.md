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
3. 测试
	+ 延迟
	+ 丢包率
	+ 看视频切换
	+ 浏览网页速度
	+ 带宽，speedtest
	+ 测试整栋大楼，扫楼，看整体延迟和丢包率
	+ 5G，一般，30ms，丢包率小于1%左右
	+ 带宽，找一个比较重要的区域，关于你的点位在哪里，测试报告给客户

***
### 20170812
1. 市场上有很多公司自行开发的mambo系统模板，几个比较大的网站上也经常能够看到一些国外(欧美，韩国)的模板，当中比较有代表性的，当属怪兽模板(templatemonster)。怪兽模板起源于美国，随即登陆亚洲市场，瞬间风靡全球的网站建设的崭新模式--怪兽网页模板开发了很多CMS网站模板，其中就包括了mambo，joomla，WordPress，magento，drupal等目前市场上最流行的模板。
2.  征文，知网搜索期刊，xtylib*, xty++,
	* 搜索期刊名字
	* 搜索期刊联系方式及征文规则
	* 查看北大核心目录
	* 查看2016综合影响因子
	*   西安市翠华路275号《无线通信技术》编辑部 ，Email : wxtx001 @ sina. co m 
3. [蓝牙mesh](https://www.techbang.com/posts/52666-official-bluetooth-bluetooth-technology-alliance-mesh-technology)
	* 藍牙技術聯盟（Bluetooth Special Interest Group，簡稱SIG）今天正式宣布，藍牙（Bluetooth）技術開始支援 Mesh 網狀網路。全新的 Mesh 功能提供多對多裝置傳輸，並特別提升建置大範圍裝置網路的通訊效能，
	* 過去市場經驗一再證明，當具備了多品牌間互通性的條件，市場就能蓬勃發展。藍牙 Mesh 技術提供的全球互通性，將確保各種不同品牌間的產品都能順利的互相搭配運作。全端解決方案（Full-Stack solution）：採用獨一無二的全端作法，從低階無線射頻至高階應用層皆完整定義，確保該技術的所有層面皆具備完整規格。
	* 以互通性為核心的規格：在規格開發過程中即做好完整的多品牌間互通性測試，而非等到規格發表之後才進行測試。
	* 通過時間考驗的工具和流程：藍牙技術聯盟20年來一直致力於提供完善的認證工具和流程，以確保全球多品牌間的互通性。
	* 「建築物自動化市場越來越重視連網照明，以及其可扮演的建築物全面自動化服務平台的角色。一個建構在藍牙 Mesh 之上的智慧照明平台，還可同時支援資產追蹤、地標(point of interest)及導航等服務，我們也相信這些加值功能是藍牙建構 Mesh 網路最理想技術的原因之一。」

### 20170813
1. Web 服务器采用开源的 Tonr ado 框架开发，使用 Pthon 开发的全栈式Web响应快速框架和
2. 《实验室研究与探索》，核心，《实验技术与管理》，核心
3. TJ武器工业
4. 战场感知是随着信息技术特别是探测技术的发 展、信息优势等概念的形成,以及新军事革命理论 的深化而产生的新概念。战场感知(battlefield awareness,BA)是指参战部队和支援保障部队对战 场空间内敌、我、友各方的兵力部署、武器配备和 战场环境(如地形、气象和水文)等信息的实时掌握 过程。战场感知除了具有传统的侦察、监视、情报、 目标指示与毁伤评估等内涵以外,最大特点在于信 息共享和信息资源的管理与控制。为了提高部队的 战场感知能力,各军事强国都很重视战场感知技术, 投入巨资研制相关系统[8-9]。
5. 传感系 统的智能化要求传感器具有以下功能:1) 智能传感 器是嵌入式微型处理器,要求在很小的传感器中嵌 入能存储、分发、处理和传输信息的芯片,对技术 和材料要求很高,而且还要保证低成本;2) 智能传 感器要有很强的自生能力,包括能供给其自身消耗 的能量,在复杂的战场环境里能够自组网和自定位; 3) 战场复杂电磁环境对传感器的影响越来越大,一 旦遭到敌方破坏或利用,智能传感器要具有自毁能 力,部分传感器节点的毁坏或退出网络不会影响整 个网络的运行。

### 20170819
1. 李贤烈, 刘捂林, 何海光. 基于 ZigBee 的移动物联网温度采集系统设计与实现[J]. 无线通信技术, 2016, 25(2): 42-45.
MLA	
	* 通过google学术，引用文献、
2. npm install xxx 安装模块

npm install xxx -g 将模块安装到全局环境中 参考http://goddyzhao.tumblr.com/post/9835631010/no-direct-command-for-local-installed-command-line-modul

npm ls 查看安装的模块及依赖

npm ls -g 查看全局安装的模块及依赖

npm uninstall xxx  (-g) 卸载模块

npm cache clean 清理缓存
3. The link state routing protocol that is most popular today in the open source world is OLSR from olsr.org. OLSR with Link Quality (LQ) extension and fisheye-algorithm works quite well.
4. Our testbed is composed of five Raspberry Pi B+ [14]. The Raspberry Pi is a credit card-sized single-board computer developed by the Raspberry Pi Foundation. The operating system mounted on these machines is OpenWrt version Chaos Calmer (r43006) with kernel 3.14.18 [15].
5. The Iperf was originally developed by NLANR/DAST as a modern alter- native for measuring TCP and UDP bandwidth performance.The Iperf allows the tuning of various parameters and UDP characteristics.

### 20170820
	The Content Centric Networks (CCN) replaces the IP narrow waist of the Internet architecture by a content layer. When a node wants to access a piece of content, it sends an Interest packet to the network. The network then, using the name of the content for routing, forwards the Interest to one or more copies of the content object. In this paper, we present the implementation of a OpenWRT OS based testbed for CCN. We analyze the performance of Optimized Link State Routing (OLSR) protocol in an indoor scenario. We transmitted single ICMP flow over UDP. For evaluation we considered hop count, delay and jitter metrics. The experimental results show that the nodes in the testbed were communicating smoothly and we got low values of delay and jitter.
	here are some other research works done for Wire- less Mesh Networks (WMNs). In [17], the authors present the architecture, security, and management of SwanMesh
	The link state routing protocol that is most popular today in the open source world is OLSR from olsr.org. OLSR with Link Quality (LQ) extension and fisheye-algorithm works quite well. 
	The operating systems mounted on these machines are Open- WRT version Chaos Calmer (15.05, r46767) with kernel 3.18.20 
	
	
	In order to further education in embedded discovery, Protomesh (prototype mesh) seeks to improve the field by providing a wireless solution for deploying Raspberry Pi workshops. Protomesh is a platform for starting up a quick ad-hoc batman-adv network. Batman-adv is an open source, kernel module native to Linux that provides a layer two mesh network routing protocol [2]. We leveraged this technology during Raspberry Pi workshops to use as a wireless infrastructure where students could freely access their Raspberry Pi across the mesh network. Network technologies such as this provide both an interactive and enriching experience. Protomesh enhances this experience by providing a solution for wireless connections and removing the burden of tethered Raspberry Pis. By allowing students to experience Raspberry Pi’s wirelessly, students are enabled to explore a new horizon of embedded education.
	
	BATMAN advanced;
	
	Protomesh is the in-house developed mesh deployment tool to assist us in manipulating a Batman-adv network across several nodes.
	
	In the future, we hope to integrate Protomesh into the ARCAM-Net (Advance Radio Communication Ad-hoc Mesh Network) project at the school. ARCAM-Net was a feasibility study on a Software Defined Radio (SDR) Network that ran on Batman-adv.
	
#### Throughput Evaluation of Raspberry Pi Devices on Multihop and Multiflow Wireless Sensor Network
	bstract—The Raspberry Pi has become one of the most popular devices used in the internet of things studies because of its flexibility and affordability for prototyping purposes. It has found its niche in wireless sensor networks as it can function both as sensor node and router node just by adding wireless adapter. Studies have employed the Raspberry Pi as WSN mesh node and sensor node. These studies looked on the performance of these devices on single flow of data and/or on limited number of hops. Indirectly, they say these devices performs poorly on multihop and multi-flow experimental scenarios. 
	
	To address the issues above studies[7] have used the Raspberry Pi [6] acting as a sensor node and mesh node in a WSN. 
	
	Most studies[9][10] involving IOT are mostly done through simulation software like Network Simulator 2 and Network Simulator 3 (NS2 & NS3) [13][14]. However it is difficult to capture the complexity of wireless communications in real environment in simulations[16]. 
	
	Raspberry Pi devices are among the most suited as wireless mesh node, capable of multi hop, self-healing, and a communication range of around 170 m[14].
	
	实施过程：
	1. Device Assembly
	2. OLSR package installation
	3. Iperf package installation
	4. Configuration
	
	测试：
	1. one hop, one flow scenario
	R2 and R1’s throughput using the command “iperf -c 192.168.10.1xx -t 10”. This was replicated for 20 times.
	2. two-hop, two-flow scenario
	
	
	The steps to measure the throughput for each hop in the set up was similar to that of scenario 1. The raspberry pi’s sent a payload of 54Mbps over the network with UDP buffer size of 160kb and sending 1470 byte datagrams for 10 seconds. For the TCP test a tcp window size of 43.8 kb was used.
	
	wireless personal area networks (WPAN)
	
#### firechat
	To monitor WiFi and Bluetooth FireChat communications, three devices were evaluated, each with particular strengths in each area. For WiFi, the HackRF One and WiFi Pineapple Nano were tested to discover the data that could be collected with each piece of hardware and the format of the collected data. To monitor Bluetooth Low Energy communication, the Ubertooth One presented the best opportunity to capture FireChat transmissions. 
	
	The Ubertooth One monitors Bluetooth and Bluetooth Low Energy (BLE) traffic. This device has a low price of $120 compared to other Bluetooth monitoring equipment that can cost thousands of dollars. 
	
	A free device exploration software tool, Blucat, that could be implemented on a Raspberry Pi was used with the Bluetooth receiver in a laptop to discover nearby devices, determine what services on the devices were using Bluetooth, find the RSSI of devices, and monitor FireChat transmissions. 
	
	Out of a list of researched software defined radios (SDRs), the HackRF One was chosen for prototyping for several reasons. First, it was one of three SDRs found that was capable of listening to a band of signals wide enough to encompass both the 2.4GHz and 5GHz wireless frequencies. Out of the three wide-band SDRs found, it was also by far the least expensive. 
	
	
	




