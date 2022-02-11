#include <Mouse.h>
#include <ps2.h>
//三个全局变量，用于排除多余的触摸板发送的数据。
int j,k,l;
//触控板连接arduino的针脚，可根据自己的需要更改。
//触控板的电源可接开发板，也可接其他电源。
#define DATA 5
#define CLOCK 6
//建立触控板对象。
PS2 mouse(CLOCK, DATA);

//以下函数实现左键，右键，中键功能。
void anjian(int data)
{
  int i,u;
  for(i = 0; i < 3 ; i++){
    if(data & 0x01){
      u = 1;
    }
    else{
      u = 0;
    }
    data = data >> 1;
    switch(i){
      case 0:
          if(u == 0){
            j = 0;
            }
          else if(j == 1){
            continue;
            }
            else{
              Mouse.click(MOUSE_LEFT);
              j = 1;
              }
          break;
      case 1:
          if(u == 0){
            k = 0;
            }
            else if(k == 1){
              continue;
              }
              else{
                Mouse.click(MOUSE_RIGHT);
                k = 1;
                }
          break;
      case 2:
          if(u == 0){
            l = 0;
            }
            else if(l == 1){
              continue;
              }
              else{
                Mouse.click(MOUSE_MIDDLE);
                l = 1;
                }
           break;
        }
       }
   }
void setup() {
  //触控板的初始化，可以调整触摸板相关参数。
  //初始化开始
  //触控板进入Reset模式
  mouse.write(0xff);
  //读取触控板自检情况
  mouse.read();
  //  mouse.read(5);
  //读取触控板ID
  mouse.read();
  
  //触控板进入Remote模式
  mouse.write(0xf0);
  
  //设定触控板分辨率
  mouse.write(0xe8);
  
  //发送分辨率
  mouse.write(0x00);
  
  //设定触控板采样率
  mouse.write(0xf3);

  //发送采样率
  mouse.write(0x14);
  
  //初始化结束。
  //开始模拟鼠标。
  Mouse.begin();
}

void loop() {
  int m;
  int x;
  int y;

  //获取触摸板数据
  mouse.write(0xeb);
  //读取触控板应答
  //mouse.read();
  //保存获取的数据
  m = mouse.read();
  x = mouse.read();
  y = mouse.read();
  anjian(m);
//调节下边的数字可以调教鼠标x，y轴的速度
  Mouse.move(5*x,-5*y,0);
  


}
