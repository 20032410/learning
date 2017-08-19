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



