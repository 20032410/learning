# 学习书籍

### 网页
* 学习git最基础书籍
	Raspberry Pi 上的[分布式网络](https://linux.cn/article-8499-1.html)

	我通过 kubeadm 发现了 Weave Net。Weave Mesh 是一个有趣的分布式网络解决方案，因此我开始了解更多关于它的内容。在 2016 年 12 月，我在 Weaveworks 收到了第一份合同工作，我成为了 Weave Net 中 ARM 支持团队的一员。

	我很高兴可以在 Raspberry Pi 上运行 Weave Net 的工业案例，比如那些需要设备更加移动化的工厂。目前，将 Weave Scope 或 Weave Cloud 部署到 Raspberry Pi 可能不太现实（尽管可以考虑使用其他 ARM 设备），因为我猜这个软件需要更多的内存才能运行良好。理想情况下，随着 Raspberry Pi 升级到 2GB 内存，我想我可以在它上面运行 Weave Cloud 了。

	在 Weave Net 1.9 中，Weave Net 支持了 ARM。Kubeadm（通常是 Kubernetes）在多个平台上工作。你可以使用 Weave 将 Kubernetes 部署到 ARM，就像在任何 AMD64 设备上一样安装 Docker、kubeadm、kubectl 和 kubelet。然后初始化控制面板组件运行的主机：
* [mesh实验](https://www.bbsmax.com/A/kvJ3E26Ddg/)笔者使用上图所示的拓扑测试了网络的连通性，发现如果计算机A和计算B是win系统的话，则需要在1、2两个节点上执行iptables -t nat  -A POSTROUTING -o eth0 -j MASQUERADE命令，也就是说，要在节点1的POSTROUTING处为笔记本B做网络地址转换（对源地址做NAT），这样B才能ping通A；同理，在节点2的POSTROUTING处为笔记本A做网络地址转换（对源地址做NAT），这样A才能ping通B。但是如果计算机A和B为linux系统的话，就不需要做NAT。因此笔者猜测win系统和linux在处理包转发或包回复时机制是不同的，至于是不是这样，还有待于研究。


* 普通的pc linux或arm linux的网络层默认情况下，是没有开启路由转发功能的，当系统收到的数据包不是发给本机的，会将数据包丢弃；因此当pc或者开发版作为路由器时，必须要激活路由转发模块。命令为：echo “1”  > /proc/sys/net/ipv4/ip_forward。这样就激活了主机的路由转发模块。
* 通过实验，笔者对网络的很多概念，包括ip地址、默认网关、路由表、arp表、路由表项、arp表项等等有了更深一步的认识。笔者觉得，ip地址虽然进行了A/B/C/D/E类划分，甚至划分了公网ip和局域网ip，可是就ip地址本身而言，它们之间没有任何本质区别，在这种自组织的ip地址分配中，可以任意使用所有ip地址。因此笔者在对全网进行ip地址规划时，将mesh骨干网的所有节点的ip地址划为一个网段，将连接在某个骨干网节点的所有客户端划为一个网段，并称其为“局域网”，连接在不同骨干网节点上的若干个局域网之间绝不能处于同一个网段，也不能和骨干网处于同一网段。示意图如下：
* 细心的实验者还应该发现，当不运行aodv协议时，这些节点之间有时也是可以连通的。其实这是对的，如果骨干网的所有节点都处于同一网段，那么arp协议会自动获取本网段内所有节点的ip地址和mac地址，并初始化节点的arp表和路由表，使得本网段的主机可以直接通信；这就和以太网内所有主机处于同一网段，也可以互相通信是一个道理。如果骨干网内的所有节点并不在同一网段的时候，就需要aodv协议来进行路由探索了。另外，骨干网内，信号不能相互覆盖的节点（即不是邻居节点），也需要aodv协议进行路由探索，aodv协议一旦探索成功路由，并将路由信息更新至内核的路由表中，其就失去作用了（可以粗略这么理解）。
* 最后，还要更正网上一些同类文章中错误的概念。他们认为节点上的两张无线网卡需要使用NAT方式连通，这属于概念性错误。其实在linux系统中，无论你插入多少张无线网卡，只要安装好了网卡驱动，这些网卡本身就是连通的，也就是说，每个网卡的ip地址和Mac地址都会被记录到路由表和arp表中，ip协议可以正确的将数据包通过相应的网卡发送出去。这和NAT方式压根没任何关系，NAT用来做网络地址转换，也就是说它会修改数据包的源地址或目的地址（对源地址做转换或对目的地址做转换，具体要根据需求来定），将其改为所设置的ip地址。NAT的作用在于，假如某些内网主机要通过一台连接在公网上的主机去上网，如果不做NAT，内网主机发送到互联网上的数据包，互联网站点是无法返回数据包的（返回的那些主机是内网主机，其ip地址为内网地址），所以这些内网主机是无法上网的；因此需要在连接到公网的那台主机上对这些内网主机数据包的源地址做NAT，将源地址转换为公网主机的ip地址，这时内网主机发送到互联网上的数据包，互联网可以做应答的，将应答包发送给这台公网主机，该主机再逆向根据NAT规则，将应答包交给某个内网主机。因此内网主机就可以上网了。
* [使用arm开发板搭建无线mesh网络](https://www.bbsmax.com/A/gGdX7wnp54/)
* 　　为了解决上述的问题，无线mesh网络应运而生。无线mesh网络从本质上讲，还是无线自组织网络（adhoc），只不过无线mesh网络在adhoc的基础上抽象出了一个骨干网（mesh）。不像adhoc网络那样，所有节点都由用户的终端设备承担，而且所有节点之间都是完全对等的关系，移动性很强。无线mesh网络的骨干网是由专门的网络设备（路由器等）组建的，而且组成骨干网的这些设备一般是不移动的或者是弱移动性的。这将解决掉上述adhoc网络所面临的很多问题。首先，骨干网节点由专门的路由设备来承担，这些路由设备不用处理用户的应用数据，只用来做路由转发的任务，因此所有的软硬件资源都是为路由转发服务的，因此可以承担大拓扑结构（大拓扑结构的网络首先需要网络设备具有足够大的存储空间来存储庞大的路由表，而且需要较强的处理器在路由表中随时查找或更新路由条目）、大数量的路由转发任务；其次，骨干网节点不移动，那么节点也不存在电力供应不足的问题，可以直接使用固定电源来供电，因此骨干网节点的这些设备在软硬件选择上，就不考虑功耗问题，性能无上限；再次，骨干网节点不移动，整个mesh网络拓扑将是稳定的，mesh网络的可靠性、应用的现实性也就具备了。下面给出adhoc网络和无线mesh网络的拓扑图示，以示其区别：

### 20170822
	There are a few software stacks to build a cloud system in ARM [5]. We are developing software stack to build virtual network suited for edge cloud.
	Generally, in order to build a cloud system, both hardware virtualization and network virtualization are required.
	There are several methods in network virtualization; VLAN (Virtual LAN), SDN (Software Defined Network) and so on. Especially, SDN is suited for large-scale network such as data center. Indeed, many data center employ SDN. There are 2 systems in SDN; OpenFlow and VXLAN. OpenFlow needs a few software stacks. So, it is suited for edge cloud.
	
	硬件可以通过以太网线，可以通过WiFi，通过蓝牙，ZigBee，RFID传输数据，又可以使用MQTT，HTTP，CoAP等各种协议，而且随着携带物联网芯片的物品的不断产生和消失，几乎不可能仅靠静态的设置来配置网络，物联网需要一个敏捷，灵活的网络。

	There are 2 systems in SDN; OpenFlow and VXLAN. OpenFlow needs a few software stacks. So, it is suited for edge cloud.
	Ryu(Python), Trema(Ruby/C) and Floodlight(Java) are OSS(Open Source Software) of OpenFlow Controller. We employ Ryu.
	A server is not different from a client. Raspberry Pi has 100 base LAN NIC (Network Interface Card).
	We measure RTT (Round Trip Time) using ping. 
	
### 电台--战术电台仿真模型研究
	本文对电台模型在战术互联网仿真中的需求 进行了分析,建立了报文处理过程模型,采用模块 化的建模方式构建了通用电台仿真模型,详细描述 了仿真模型中各模块的功能,分析了仿真模型中的 传播模型和计算模型。通过 VRNET Developer 网络 仿真平台,以 VHF 电台为例,构建了仿真模型并在 移动和干扰条件下对仿真模型进行了仿真,仿真结 果表明,构建的仿真模型能够满足战术互联网仿真的通信要求。
	·移动模块:负责仿真中节点的移动特性管理。 当电台位置发生变化后,该模块实时计算新的位置 坐标,及时提供给相应模块。其中包含的参数有:节 点的移动速度、节点速度更新间隔、节点平面运行 角度、节点控制范围、节点位置、节点位置更新间隔 等。·设备地址模块:进行数据设备地址(通常为 IPv4 地址)和电台 MAC 地址之间的映射。·状态检测模块:电台状态检测模块,根据电台 的参数设置,来判断电台是否处于使能状态。·通告板模块:用于模型内各模块之间的信息 交互。在节点内部,一些模块的信息可能为另外一 些模块所需要,若这些模块间直接进行交互,会造 成模型间的耦合度过高,不利于模型的扩展和重 用。因此,采用通告板模块来统一负责节点内部信 息的交互。·接口模块:用于电台传输速率接口的管理和 控制,主要有 K 接口和 E1 接口等。	·I P 配 置 模 块 :用 于 管 理 I P 接 口 的 模 块 ,在 具 备 IP 体系结构的电台模型中,识别节点内所有的网 络接口,为其分配 IP 地址,并作出相应的处理。
	·基本电台模块:实现无线信道接入的模拟。其 中包含了电台的基本参数信息,主要有:载频、频率 带宽、发送数据率、调制方式、发送功率、接收灵敏 度、热噪声功率、天线高度、天线水平角、天线仰角、 路径损耗计算模型等。
	·路由模块:分发路由协议信息,计算基于电台 MAC 地址的路由,对数据报文进行转发。
### 基于Mesh网络的远程控制系统研究与实现_赵凯20170830
	1) AIN5600 双模基站用于构建 Mesh 骨干网络,其 2. 4 G 模块用于其他设备的接入服务,5. 8 G 模块 用于组建 Mesh 网络,彼此之间形成网格状网络进而 构成骨干网。	2) N11OD 用于车载跨基站快速切换服务,下行 链路只对其它终端提供有线接入服务,而不提供无线 接入服务,其自身的 2. 4 G 模块用于上行链路接入 Mesh 骨干网络。
	3) N11OD-AP 的 2. 4 G 模块用于终端设备无线 接入,而其上行链路通过有线与 N11OD 进行连接。
	CO2128 主要分为 AP 模式和 AD-HOC 模式[5], 视距遥控采用 AD-HOC 模式,因为两者之间不需要 借助中继; 远程遥控采用 AP 模式,车辆与遥控之间 根据需求架设一定数量的 Mesh 基站用来传递数据
	丢包率
	研究了组建基于 Mesh 网络 的战术互联网
### 基于Mesh的航母编队通信网仿真_皋伟
	本文使用 OPNET 进行骨干 Mesh 网络性能仿真。 OPNET 提供 3 层建模机制,包括网络模型、节点模型 和进程模型。3 层建模机制分别与实际的网络、设 备、协议相互对应,全面反映网络的相关特性
	1) 物理层: 通过 wlan_port_tx_0_0,wlan_port_rx_0 _0 进行数据的发送和接收。2) 数据链路层: Wireless_lan_mac 模块,可以完整 模拟 CSMA/CA 协议。3) 网络层: 含有 arp,ip,ip_encap 等模块。arp 模 块是运行地址转换协议和逆地址转换协议,实现 IP 地址和物理地址的转化。ip 模块是为节点配置具体 的路由协议。根据节点运行路由协议,将到达的 IP 数据包发送到相应的接口上。ip_encap 模块将上层 的数据包封装为 IP 数据包,同时将下层获得的 IP 数 据包解封装,再将数据发送给传输层。这个模块工作 在上层模块与 IP 模块之间。4) 传输层与应用层: 包括 udp,tcp 等模块,分别 在 IP 层之上提供无连接的传输服务。5) 应用层: application,dhcp 等模块负责网络业 务的产生和网络节点地址的自动分配
	
### BLEMesh网络协议综述_徐春燕	BLE 有三种工作模式:一是关闭模式,此时没有任何时钟在运行,芯片完全断电,没有任何设备能够进行连接。 二是睡眠模式,此时仅有 low_power_clk 在运行,这 种情况下只有达到预定的睡眠时间或者有 wake_up 唤 醒请求,睡眠模式才能转换为正常工作的模式。 三是正 常工作模式,在这种模式下,可以进行广播、扫描、连接 以及实时数据包的处理。 主时钟 hclk 打开,若数据需要 进行加密,加密时钟 crypt_clk 也会打开。
### 基于OLSR协议的无线Mesh节点的设计与开发_冯宪
	putty
	iperf
	lxchariot，产生并且模拟真实的流量情况，使用的是end to end方式对网络设备或系统在实际环境中的性能进行长时间的压力测试。
	wifi连接
	speedtest
	throughout
	* 单跳访问测试
	* 吞吐量测试
	* 响应时间，主要完成的是进行1次TCP通信的时间，包括最短时间、平均时间以及最长时间。
	* lxchariot软件进行throught测试时，还统计了响应时间
	* 组建小型的无线mesh网
	* 丢包率
	
	Yu M, Wang Q, Zhang M, et al. Facile fabrication of raspberry-like composite microspheres for the construction of superhydrophobic films and applications in highly efficient oil–water separation[J]. RSC Advances, 2017, 7(63): 39471-39479.
MLA	

	
	
	
	

	
	




	
