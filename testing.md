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
2. 
