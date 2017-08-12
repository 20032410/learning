# 学习书籍

### 网页
* 学习git最基础书籍
	Raspberry Pi 上的[分布式网络](https://linux.cn/article-8499-1.html)

	我通过 kubeadm 发现了 Weave Net。Weave Mesh 是一个有趣的分布式网络解决方案，因此我开始了解更多关于它的内容。在 2016 年 12 月，我在 Weaveworks 收到了第一份合同工作，我成为了 Weave Net 中 ARM 支持团队的一员。

	我很高兴可以在 Raspberry Pi 上运行 Weave Net 的工业案例，比如那些需要设备更加移动化的工厂。目前，将 Weave Scope 或 Weave Cloud 部署到 Raspberry Pi 可能不太现实（尽管可以考虑使用其他 ARM 设备），因为我猜这个软件需要更多的内存才能运行良好。理想情况下，随着 Raspberry Pi 升级到 2GB 内存，我想我可以在它上面运行 Weave Cloud 了。

	在 Weave Net 1.9 中，Weave Net 支持了 ARM。Kubeadm（通常是 Kubernetes）在多个平台上工作。你可以使用 Weave 将 Kubernetes 部署到 ARM，就像在任何 AMD64 设备上一样安装 Docker、kubeadm、kubectl 和 kubelet。然后初始化控制面板组件运行的主机：


	
