# arduino-ps/2-touchpad
&emsp;&emsp;这个项目的起因是我想在台式机上使用触控板，看了很多块触控板，性能都没笔记本上那块强。唯一看中的是苹果的妙控板，就是价格太贵了，承受不起。所以到闲鱼整了一块笔记本拆机的触控板，看看能不能搞到台式机上用。虽然台式机上也有ps/2接口，但是直连触控板只能移动鼠标。安装驱动无法识别，体验非常不好，还不如普通的鼠标。所以萌生了使用arduino开发板驱动ps/2触控板的想法。

#  项目介绍
&emsp;&emsp;ps/2触控板需要接到开发板的的引脚是data和clock。电源和接地引脚可以接到开发板相应位置，也可以接到其他电源上。具体针脚怎么找，可以搜索触控板芯片的型号，找官方的说明。也可以找笔记本的电路图。
  
&emsp;&emsp;项目使用了ps/2zhuji库和Mouse库。ps/2zhuji库和Mouse库可以在arduino ide里下载。ps/2zhuji库在我的另一个[GitHub仓库](https://github.com/cike-567/arduino-ps2zhuji "前往仓库")。也可以下载。

# 本项目的限制
  
&emsp;&emsp;只能使用基于32u4或SAMD micro的开发板。原因是这些开发板有原生的usb端口。例如Arduino micro、pro micro 和 Leonardo。

#  项目进展

  ## 2022.2.11
&emsp;&emsp;目前实现了，鼠标移动，左键和右键。可以调节鼠标的移动速度，以及触控板的一些参数。具体看项目的注释。
  ## 2022.3.13
&emsp;&emsp;修改了代码，提高了性能。
