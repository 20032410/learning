# openwrt
### 打patch
	内核的打法：
	操作步骤：
	1、 进入Openwrt目录， make target/linux/{clean,prepare} V=s QUILT=1，这一步将linux内核清理干净，准备修改
	2、 进入解压出来的linux内核目录，cd build_dir/target-mipsel_24kec+dsp_uClibc-0.9.33.2/linux-ramips_mt7621/linux-2.6.36/
	3、 可以用quilt series来查看对当前内核有什么patch，
	4、 使用quilt new platform/0928-sky-mtd.patch，准备开始新patch
	5、 quilt edit drivers/mtd/mtdpart.c
	进入drivers/mtd目录，编辑mtdpart.c，函数split_rootfs完成flash分区切分
	ROOTFS_SPLIT_NAME就是rootfs_data，你模仿这个方式，划分好分区name，size和offset，然后调用add_one_partition添加分区。
	6、 将代码修改好后，运行 quilt refresh
	7、 回到最顶层目录，执行 make target/linux/update，这时候会生成patch，你可以在target/linux/ramips/patches-2.6.36目录下看到0928- sky-mtd.patch这个patch
	8、 客户还要在升级的时候写入一个分区，还要做一个标记，这个你可以直接修改package/base-files/files/sbin/sysupgrade脚本，这个不是用 patch形式来修改的
	9、 执行make V=s编译生成image。

1. [http://blog.csdn.net/walker0411/article/details/51916959](http://blog.csdn.net/walker0411/article/details/51916959)
	OpenWrt内核打补丁方法
	首选明确，iphone5、6的product id为0x12a8， ipad的product id为0x129a。

make target/linux/clean V=99 
进入Openwrt目录， make target/linux/clean V=99，将内核清理干净。

make target/linux/prepare V=99 
make target/linux/prepare V=99，将内核应用所有patch并生成最新代码到build_dir目录下。

cd build_dir/linux-ar71xx_generic/linux-3.3.8 
进入最新kernel的source code目录。

quilt new platform/965-ipheth-iphone5-6-support.patch 
新建965-ipheth-iphone5-6-support.patch，并指定保存目录到patches/platform/下。

quilt edit drivers/net/usb/ipheth.c 
编辑ipheth.c，增加对iphone5、6及ipad的支持。

quilt refresh 
保存patch。

make target/linux/update V=99 
进入Openwrt目录， make target/linux/update V=99，将patch应用，此时会生成新patch，到target/linux/ar71xx/patches-3.3/下查看。

2. 给LEDE/OpenWRT打补丁
参考资料
https://wiki.openwrt.org/doc/devel/patches
https://lede-project.org/docs/guide-developer/use-patches-with-buildsystem

3. 使能patch
到根目录下clean以后compile就ok了
make package/wifidog/clean V=99
make package/wifidog/compile V=99
复制代码

	补充：
	1、如果是修改kernel源码的话
	make target/linux/clean V=99
	
OpenWrt构建系统 - 构建顺序

tools： automake、autoconf、sed、cmake
toolchain/binutils：as、ld，…
toolchain/gcc：gcc、g++、cpp，…
target/linux：内核模块
package： 核心pacakge
target/linux：内核镜像
target/linux/image：最终的固件文件
这里的构建顺序对理解OpenWrt整个系统的结构很有帮助，再后面深入学习OpenWrt的结构后应该再回头看看。

4. [Working with patches in the build system](https://lede-project.org/docs/guide-developer/use-patches-with-buildsystem)

### edit existing patch
	Edit an existing patch

Start with preparing the source directory:

make package/example/{clean,prepare} V=s QUILT=1
Change to the prepared source directory.

cd build_dir/target-*/example-*
List the patches available:

quilt series
Advance to the patch that needs to be edited:

quilt push 010-main_code_fix.patch
When passing a valid patch filename to push, quilt will only apply the series until it reaches the specified patch
If unsure, use quilt series to see existing patches and quilt top to see the current position
If the current position is beyound the desired patch, use quilt pop to remove patches in the reverse order
You can use the “force” push option (e.g. quilt push -f 010-main_code_fix.patch) to interactively apply a broken (i.e. has rejects) patch
Edit the patched files using the quilt edit command, repeat for every file that needs changes.

quilt edit src/main.c
Check which files are to be included in the patch:

quilt files
Review the changes with quilt diff.

quilt diff
If the diff looks okay, proceed with quilt refresh to update the current patch with the changes made.

quilt refresh
Change back to the toplevel diretory of the buildroot.

cd ../../../
To move the updated patch file over to the buildroot, run update on the package:

make package/example/update V=s
Finally rebuild the package to test the changes:

make package/example/{clean,compile} package/index V=s

***
[如何在Openwrt上，针对内核创建自定义Patch?](http://www.cnblogs.com/lagujw/p/4305255.html)
[openwrt patch生成](http://www.cnblogs.com/xuyh/p/6278937.html)
[OpenWrt patch方法](http://blog.csdn.net/wwx0715/article/details/25160361)
[编译openwrt全过程（超详细）](http://blog.csdn.net/mirkerson/article/details/7287931)
	应用程序--附件--终端
sudo apt-get update      (更新）
安装编译需要的组件：
sudo apt-get install gcc 
sudo apt-get install g++ 
sudo apt-get install binutils 
sudo apt-get install patch 
sudo apt-get install bzip2 
sudo apt-get install flex 
sudo apt-get install bison 
sudo apt-get install make 
sudo apt-get install autoconf 
sudo apt-get install gettext 
sudo apt-get install texinfo 
sudo apt-get install unzip 
sudo apt-get install sharutils 
sudo apt-get install subversion 
sudo apt-get install libncurses5-dev 
sudo apt-get install ncurses-term 
sudo apt-get install zlib1g-dev 
sudo apt-get install gawk
sudo apt-get install asciidoc
sudo apt-get install libz-dev
编译环境搭建完成
mkdir openwrt 创建一个openwrt文件夹
cd openwrt    进入openwrt文件夹
svn co svn://svn.openwrt.org/openwrt/branches/backfire  下载官网的源码
./scripts/feeds update -a     更新软件包
./scripts/feeds install -a    安装软件包
make menuconfig 进入定制界面（里面可以选择芯片的型号，集成的组件等等，根据实际情况选择）
defconfig
make V=99   （开始编译）
剩下的就是等待了，第一次编译需要的时间相对比较长，这个跟你的电脑配置和网速有关。

### 20170905
1. 安装vpn
2. 代理

	ping：一个常用的网络测试工具。通过交换ICMP的echo和reply报文来实现其功能。它在测量路由的RTT、丢包率以及检测远端系统防火墙规则时很有用。ping的变种有更漂亮的界面（例如，noping）、多协议支持（例如，hping）或者并行探测能力（例如，fping）。（LCTT 译注：延伸阅读。）
	bmon：一个基于命令行的带宽监测工具，可以显示各种接口相关的信息，不但包括接收/发送的总量/平均值统计数据，而且拥有历史带宽使用视图。
	speedometer：一个可视化某个接口发送/接收的带宽使用的历史趋势，并且基于ncurses的条状图进行显示的终端工具。
	traceroute：一个能发现从本地到远端主机的第三层路由/转发路径的网络发现工具。它发送限制了TTL的探测报文，收集中间路由的ICMP反馈信息。它在排查低速网络连接或者路由相关的问题时很有用。traceroute的变种有更好的RTT统计功能（例如，mtr）。
	监控eth1

iftop -i eth1
	iftop -F 192.168.1.0/24 or 192.168.1.0/255.255.255.0
	第一行：带宽显示

中间部分：外部连接列表，即记录了哪些ip正在和本机的网络连接

中间部分右边：实时参数分别是该访问ip连接到本机2秒，10秒和40秒的平均流量

=>代表发送数据，<= 代表接收数据

底部三行：表示发送，接收和全部的流量

底部三行第二列：为你运行iftop到目前流量

底部三行第三列：为高峰值

底部三行第四列：为平均值
	
***
	使用Ping检查连通性有五个步骤： 

　　1. 使用ipconfig /all观察本地网络设置是否正确； 
　　2. Ping 127.0.0.1，127.0.0.1 回送地址Ping回送地址是为了检查本地的TCP/IP协议有没有设置好； 
　　3. Ping本机IP地址，这样是为了检查本机的IP地址是否设置有误； 
　　4. Ping本网网关或本网IP地址，这样的是为了检查硬件设备是否有问题，也可以检查本机与本地网络连接是否正常；（在非局域网中这一步骤可以忽略） 
　　5. Ping远程IP地址，这主要是检查本网或本机与外部的连接是否正常。 
　　
***
	带宽测试通常采用UDP模式，因为能测出极限带宽、时延抖动、丢包率。在进行测试时，首先以链路理论带宽作为数据发送速率进行测试，例如，从客户端到服务器之间的链路的理论带宽为100Mbps，先用-b 100M进行测试，然后根据测试结果（包括实际带宽，时延抖动和丢包率），再以实际带宽作为数据发送速率进行测试，会发现时延抖动和丢包率比第一次好很多，重复测试几次，就能得出稳定的实际带宽。 
	UDP模式 
	服务器端： 
	iperf -u -s 
	客户端： 
	iperf -u -c 192.168.1.1 -b 100M -t 60 
	在udp模式下，以100Mbps为数据发送速率，客户端到服务器192.168.1.1上传带宽测试，测试时间为60秒。 
	iperf -u -c 192.168.1.1 -b 5M -P 30 -t 60
	客户端同时向服务器端发起30个连接线程，以5Mbps为数据发送速率。
	iperf -u -c 192.168.1.1 -b 100M -d -t 60 
	以100M为数据发送速率，进行上下行带宽测试。
	
	操作举例：

1）TCP测试

服务器执行：#iperf -s -i 1 -w 1M

客户端执行：#iperf -c host -i 1 -w 1M

其中-w表示TCP window size，host需替换成服 务器地址。

2）UDP测试

服务器执行：#iperf -u -s

客户端执行：#iperf -u -c 10.32.0.254 -b 900M  -i 1  -w 1M  -t 60

其中-b表示 使用带宽数量，千兆链路使用90%容量进行测试就可以了。

	root@LEDE:~# iperf -u -c 192.168.2.1 -b 100M -t 60
------------------------------------------------------------
Client connecting to 192.168.2.1, UDP port 5001
Sending 1470 byte datagrams, IPG target: 117.60 us (kalman adjust)

UDP buffer size:  224 KByte (default)

[  3] local 192.168.2.140 port 56457 connected with 192.168.2.1 port 5001
[ ID] Interval       Transfer     Bandwidth
[  3]  0.0-60.0 sec   183 MBytes  25.6 Mbits/sec
[  3] Sent 130738 datagrams
[  3] Server Report:
[  3]  0.0-60.0 sec   182 MBytes  25.4 Mbits/sec   2.270 ms 1247/130738 (0.95%)

***
root@LEDE:~# iperf -u -c 192.168.2.1 -b 5M -p 30 -t 60

Client connecting to 192.168.2.1, UDP port 30
Sending 1470 byte datagrams, IPG target: 2352.00 us (kalman adjust)

UDP buffer size:  224 KByte (default)

[  3] local 192.168.2.140 port 37318 connected with 192.168.2.1 port 30
[ ID] Interval       Transfer     Bandwidth
[  3]  0.0-60.0 sec  1.44 KBytes   196 bits/sec
[  3] Sent 1 datagrams
read failed: Connection refused
[  3] WARNING: did not receive ack of last datagram after 5 tries.

***
root@LEDE:~# iperf -u -c 192.168.2.1 -b 100M -d -t 60
------------------------------------------------------------
Server listening on UDP port 5001
Receiving 1470 byte datagrams
UDP buffer size:  224 KByte (default)
------------------------------------------------------------
------------------------------------------------------------
Client connecting to 192.168.2.1, UDP port 5001
Sending 1470 byte datagrams, IPG target: 117.60 us (kalman adjust)
UDP buffer size:  224 KByte (default)
------------------------------------------------------------
[  4] local 192.168.2.140 port 35334 connected with 192.168.2.1 port 5001
[  3] local 192.168.2.140 port 5001 connected with 192.168.2.1 port 36882
[ ID] Interval       Transfer     Bandwidth        Jitter   Lost/Total Datagrams
[  3]  0.0-60.0 sec  83.3 MBytes  11.7 Mbits/sec   2.089 ms  607/60055 (1%)
[  3] WARNING: ack of last datagram failed after 10 tries.
[  4]  0.0-60.0 sec   110 MBytes  15.4 Mbits/sec
[  4] Sent 78419 datagrams
[  4] Server Report:
[  4]  0.0-60.1 sec   109 MBytes  15.3 Mbits/sec   3.691 ms  353/78419 (0.45%)

	tcp 测试：
	服务器端：
	iperf -s -i 1 -M
	客户端：
	iperf -c 192.168.2.1 -i 1 -t 10 -w 20k
***	
	通常采用UDP模式，因为能测出极限带宽、时延抖动、丢包率
***
	root@LEDE:~# iperf -u -c 192.168.2.1 -b 100M -t 60
------------------------------------------------------------
Client connecting to 192.168.2.1, UDP port 5001
Sending 1470 byte datagrams, IPG target: 117.60 us (kalman adjust)
UDP buffer size:  224 KByte (default)

[  3] local 192.168.2.140 port 35985 connected with 192.168.2.1 port 5001
[ ID] Interval       Transfer     Bandwidth
[  3]  0.0-60.0 sec   208 MBytes  29.1 Mbits/sec
[  3] Sent 148378 datagrams
[  3] Server Report:
[  3]  0.0-60.0 sec   208 MBytes  29.0 Mbits/sec   1.686 ms  130/148378 (0.088%)
iperf -u -c 192.168.2.1 -b 100M -t 60 -i 1
		吞吐量(throughput)、抖动率（jitter)、丢包率(drop ...
	interval（间隔），transfer（传输容量），bandwidth（带宽），jitter（时延抖动），lost/total(丢包)，datagrams（丢包率）
	
*** 
	brctl show
brctl addif br-lan eth0
ifconfig eth0 down
ifconfig eth0 0.0.0.0 up
brctl show


### 2017.09.24
	1. 各位的路由器很多都比较小，然而要塞入一个完整的py可能已经很勉强了，所以，就出现了Python-Mini这个软件包，可以在尽量小的尽可能实现py运行环境。
那么就开始安装吧
ssh登陆到路由器后台，然后执行

opkg update
opkg install python-mini

然而安装了OpenWrt Chaos Calmer(15.05)及之后版本的同学需要安装另一个包（Python-Light）

opkg update
opkg install python-light

这样就完成了一个最小的python环境的安装了
如果你还需要其他的模块你可以直接opkg安装，例如你要openssl模块你就可以在终端执行

opkg install ptyhon-openssl


	2. opkg update

1.安装python及ssl

opkg install libffi

opkg install python-mini

opkg install python

opkg install python-openssl

2.安装pip

wget –no-check-certificate https://bootstrap.pypa.io/get-pip.py

python get-pip.py

3.[老高的技术博客](https://blog.phpgao.com/xiaomi_router_python.html)








