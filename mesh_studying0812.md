# 学习书籍

### GitHub入门与实践
	学习git最基础书籍
	
### 每天读一点英文之宁静的心灵盛宴
	坚持每天学习英文
	Done
	
### 基于OPENWRT开源路由器的智能网关系统设计与实现
	增加usb扩展
	opkg install kmod-usb-core
	opkg install kmod-usb-uhci kmod-usb-storage kmod-usb2 kmod-usb-ohci
	
### Linux企业应用案例精辟
	主机监控应用案例
	安装Ntop
	libpacp
	zlib
	gd
	libpng
	安装Nagios
	集群监控ganglia
	cheops-ng配置
	ossim
	LDAP管理
	企业集群HA-OSCAR
	Heartbeat
	
### 无线Mesh网络管理技术的研究
	移动代理 ：移动Agent技术；验证了移动Agent与SNMP相结合的无线Mesh网络管理体系
	无线Mesh网络：WMN：Wireless Mesh Networks，无线网状网或无线网状网，具有动态组网、多跳传输、站点移动、业务多样等动态特性。
	简单网络管理协议（SNMP）是目前TCP/IP网络中应用最为广泛的网络管理协议。
	分为基础设施/骨干无线Mesh网络、客户端无线Mesh网络、混合虚线网络(Hybrid WMNs)三大类。
	客户端无线Mesh网络（Client WMNs），终端Mesh，（手机Mesh？）
	混合无线网状网（Hybrid WMNs），基础设施网提供了到其它网络（互联网，WiFi，WiMAX，蜂窝网和传感器网络）
	Mesh路由器，Mesh客户端
	
	* 无线Mesh宽带接入城域网，可以作为外来WiMAX无线城域网的扩展和补充
	* 校园网，容易安装，成本低并且能够调整节点数量和位置，并能实现室内外无缝漫游
	* 医院
	* 旅游休闲场所
	* 需要快速部署或临时安装的场所，如展览会、交易会、灾难救援等。
	
	现有无线网络管理方案
	* ANMP
	* 基于策略的网络管理
	* 移动Agent
	* 代理传输协议：两种代理传输协议ATP(Agent Transfer Protocol)和SNMP
	(Simple Network Management Protocol)
	* 程序图和时序图
	
### 小型化无线MESH路由器研究与实现
	option mode 'adhoc' 网卡可有ap、sta、adhoc
	option ssid 'MESH'
	option proto 此为MESH协议的选择，mpctrl if
	1. MESH节点IP地址设置
	协议会自动生成一个虚拟接口mpm0，需要在其上进行MESH接口IP地址配置，修改文件中接口的lan的配置，在option ifname 'etho'中添加上协议生成的虚拟接口mpm0，并配置option type为bridge，这样接口eth0、mpm0就会桥接成一个br-lan接口，通过ifconfig可查看结果，之后需要对个桥接接口的IP地址等进行设置。