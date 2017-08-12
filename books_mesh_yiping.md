#书籍《无线网络攻防教程》
## Openwrt
1. 最核心的mesh路由功能是在MIT RoofNet项目基础上进行开发实现的。
2. 第一是网卡驱动MadWiFi，针对Atheros公司的网卡开发，允许直接收发802.11原始数据包，即完全读写数据包中所有信息，使我们很方便在各个层次中加入特有规则与算法
3. 第二是MadWiFi提供了VAP功能，即将一块网卡虚拟成多块使用，这正满足了无线Mesh网络中Mesh路由器既能与其他节点通信又要与用户通信这一需求。
4. 第三是模块化的软件路由器Click，能帮助实现各种路由算法，帮助开发者验证路由算法的可用性
5. 第四就是路由算法SrcRR，它是无线Mesh网络路由算法之一，能够随时监控各条链路跃点数的大小。
6. 最初在WRT54G基础上增强原有的功能，制作出针对某种特性需求的Firmware
7. 进行交叉编译

##Click原理
1. 麻省理工学院Eddie Kohler博士开发的网络应用模型

##SrcRR路由协议
1. 是DSR与ETT的结合
2. SrcRR简略流程图
3. SR2ETTstat模块，整个路由中比较重要的一块，负责链路质量探测功能
4. SR2GateWaySelect将主要负责从诸多互联网网关中南选择最优的网关
5. 路由数据选择过程
6. ETT值计算
7. 编译使用内置broadcom 4704芯片的ASUS的WL500W无线路由
8. openwrt，kamikaze
9. Click在二层与三层之间的模块化路由设计软件，采用了虚拟网卡与实网卡通信方法实现数据包转发
10. 加密
11. MSAPP

##常用攻击工具
1. AirCrak-ng
2. NetStumbler
3. BackTrack