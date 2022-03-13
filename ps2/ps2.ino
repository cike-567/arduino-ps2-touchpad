#include <Mouse.h>
#include <ps2zhuji.h>

//触控板连接arduino的针脚，可根据自己的需要更改。
//触控板的电源可接开发板，也可接其他电源。
#define DATA 5
#define CLOCK 6
//建立触控板对象。
PS2 mouse(CLOCK, DATA);

void setup() {
  //触控板的初始化，可以调整触摸板相关参数。
  //初始化开始
  //重置触控板
  mouse.write(0xff);
  //读取触控板自检情况
  mouse.read();
  //读取触控板ID
  mouse.read();
  
  //触控板进入Stream模式。（流模式？）
  mouse.write(0xEA);
  
  //设定触控板分辨率
  mouse.write(0xe8);
  
  //发送分辨率
  mouse.write(0x03);
  
  //设定触控板采样率
  mouse.write(0xf3);

  //发送采样率
  mouse.write(0xc8);

  //设置缩放比例
  mouse.write(0xE7);

  //使触控板发送数据
  mouse.write(0xF4);

  //初始化结束。
  //开始模拟鼠标。
  Mouse.begin();
  
}

void loop() {
  int m;
  int x;
  int y;

  //获取触摸板数据
  //mouse.write(0xeb);
  //读取触控板应答
  //mouse.read();
  //获取数据
  m = mouse.read();
  x = mouse.read();
  y = mouse.read();

  //以下函数实现左键，右键功能。
  if(bitRead(m,0)==1){
    Mouse.click(MOUSE_LEFT);
    }

  if(bitRead(m,1)==1){
    Mouse.click(MOUSE_RIGHT);
    }
  
//调节下边的数字可以调教鼠标x，y轴的速度
  Mouse.move(5*x,-5*y,0);

}
