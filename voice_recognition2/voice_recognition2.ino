/*3、5、6、9、10、11，可用于输出8-bit PWM波。对应函数 analogWrite() 。
/*
改程序为口令模式，先说 xiao xiao zai ma，然后说具体关键词 
可通过串口来查看识别结果
接线定义:
3.3V GND 选一组接就行
  3V3--3.3V
  GND--GND
  SCK--A5
  MI--A4
  MO--A3
  CS--A2
  RST--D5
  IRQ--D3
  WR--GND
*/
#include "LD3320.h"

//LD3320 variables
LD3320 WE;
u8 nAsrStatus=0;
u8 nAsrRes=0;
extern u8  ucRegVal;
u8 flag=0;

//Motor Driver variables
int DIR1 = 46;     //M1 Direction Control
int PWM1 = 6;
int SLP1 = 31;    

int DIR2 = 48;     //M2 Direction Control
int PWM2 = 9;
int SLP2 = 33; 

int DIR3 = 50;     //M3 Direction Control
int PWM3 = 10;
int SLP3 = 35; 

int DIR4 = 52;    //M4 Direction Control
int PWM4 = 11;
int SLP4 = 37; 

unsigned int Speed = 10;

void setup() {
  Serial.begin(9600);
  WE.LD3320_IO_Init();
  WE.LD_Reset();
  attachInterrupt(1, ProcessInt, FALLING);
  nAsrStatus = LD_ASR_NONE;    //初始状态：没有在作ASR
  SCS_0;

  //电机引脚设置
/*  pinMode(DIR1, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(DIR3, OUTPUT);
  pinMode(PWM3, OUTPUT);
  pinMode(DIR4, OUTPUT);
  pinMode(PWM4, OUTPUT);

  digitalWrite(PWM1, LOW);
  digitalWrite(PWM2, LOW);
  digitalWrite(PWM3, LOW);
  digitalWrite(PWM4, LOW);

  pinMode(SLP1,INPUT_PULLUP);
  pinMode(SLP2,INPUT_PULLUP);
  pinMode(SLP3,INPUT_PULLUP);
  pinMode(SLP4,INPUT_PULLUP);*/
  delay(10);
  Serial.println("Start\r\n");  

  
}

void loop() {
  //qianjin();
  switch(nAsrStatus)
    {
      case LD_ASR_RUNING:
      case LD_ASR_ERROR:  
           break;
      case LD_ASR_NONE:
      {
        nAsrStatus=LD_ASR_RUNING;
        if (WE.RunASR()==0)  /*  启动一次ASR识别流程：ASR初始化，ASR添加关键词语，启动ASR运算*/
        {
          nAsrStatus = LD_ASR_ERROR;
        }
        break;
      }

      case LD_ASR_FOUNDOK: /* 一次ASR识别流程结束，去取ASR识别结果*/
      {
        nAsrRes = WE.LD_GetResult();   /*获取结果*/                        
        User_Modification(nAsrRes);
        nAsrStatus = LD_ASR_NONE;
        break;
      }
      case LD_ASR_FOUNDZERO:
      default:
      {
        nAsrStatus = LD_ASR_NONE;
        break;
      }
    } 
//Serial.println("Voce\r\n");
}

void User_Modification(u8 dat)
{
  
//Serial.println("Voce\r\n");
    switch(nAsrRes)      /*对结果执行相关操作,客户修改*/
    {
      case CODE_DMCS:    
          Serial.println("dai ma ce shi\r\n"); 
          break;
          
//     case CODE_CSWB:    
//          Serial.println("ting zhi\r\n");
//           break;
      
      case CODE_1KL1: 
          Serial.println("zhan qi lai\r\n");
      case CODE_1KL2:   
          Serial.println("zuo xia\r\n"); 
           break;
      case CODE_1KL3:  
          Serial.println("zuo qi lai\r\n"); 
           break;
      case CODE_1KL4:          
          Serial.println("tang xia\r\n"); 
           break;
      case CODE_2KL1:  
          //qianjin();
          Serial.println("qian jin\r\n"); 
           break;
      case CODE_2KL2:  
          //houtui();
          Serial.println("hou tui\r\n"); 
           break;
      case CODE_2KL3: 
          //xiangzuo();
          Serial.println("xiang zuo\r\n");
           break;
      case CODE_2KL4:  
          //xiangyou();
          Serial.println("xiang you\r\n"); 
          break;         
      case CODE_3KL1:  
          //tingzhi();
          Serial.println("sha che\r\n"); 
           break;
      case CODE_3KL2: 
          Serial.println("guan bi kong tiao\r\n"); 
           break;
      case CODE_5KL1:  
          Serial.println("kai qi kong tiao"); 
           break;
      
      default:break;
    }
  

  
}

void ProcessInt(void)
{
  u8 nAsrResCount=0;
  ucRegVal = WE.LD_ReadReg(0x2B);
  WE.LD_WriteReg(0x29,0) ;
  WE.LD_WriteReg(0x02,0) ;
  if((ucRegVal & 0x10)&&WE.LD_ReadReg(0xb2)==0x21&&WE.LD_ReadReg(0xbf)==0x35)     /*识别成功*/
  { 
    nAsrResCount = WE.LD_ReadReg(0xba);
    if(nAsrResCount>0 && nAsrResCount<=4) 
    {
      nAsrStatus=LD_ASR_FOUNDOK;
    }
    else
    {
      nAsrStatus=LD_ASR_FOUNDZERO;
    } 
  }                              /*没有识别结果*/
  else
  {  
    nAsrStatus=LD_ASR_FOUNDZERO;
  }
    
  WE.LD_WriteReg(0x2b, 0);
  WE.LD_WriteReg(0x1C,0);/*写0:ADC不可用*/
  WE.LD_WriteReg(0x29,0);
  WE.LD_WriteReg(0x02,0);
  WE.LD_WriteReg(0x2B,0);
  WE.LD_WriteReg(0xBA,0);  
  WE.LD_WriteReg(0xBC,0);  
  WE.LD_WriteReg(0x08,1);   /*清除FIFO_DATA*/
  WE.LD_WriteReg(0x08,0);  /*清除FIFO_DATA后 再次写0*/
}


/*void qianjin()
{     
      analogWrite(PWM1, 40);
      analogWrite(PWM2, 40);
      analogWrite(PWM3, 40);
      analogWrite(PWM4, 40);
      delay(10); 
      digitalWrite(DIR1, LOW);   //后面
      digitalWrite(DIR2, LOW);
      digitalWrite(DIR3, HIGH );
      digitalWrite(DIR4, HIGH);
      delay(10); 
      
}


void houtui()

{     
      analogWrite(PWM1, Speed);
      analogWrite(PWM2, Speed);
      analogWrite(PWM3, Speed);
      analogWrite(PWM4, Speed);
      delay(10); 
      digitalWrite(DIR1, HIGH);   //后面
      digitalWrite(DIR2, HIGH);
      digitalWrite(DIR3, LOW );
      digitalWrite(DIR4, LOW );
      delay(10); 
}

void xiangzuo()
{

     
      analogWrite(PWM1, Speed);
      analogWrite(PWM2, Speed);
      analogWrite(PWM3, Speed);
      analogWrite(PWM4, Speed);
      delay(10);
      digitalWrite(DIR1, HIGH);   //左边
      digitalWrite(DIR2, LOW);
      digitalWrite(DIR3, LOW );
      digitalWrite(DIR4, HIGH );
      delay(10); 
}

void xiangyou()
{
      
      analogWrite(PWM1, Speed);
      analogWrite(PWM2, Speed);
      analogWrite(PWM3, Speed);
      analogWrite(PWM4, Speed);
      delay(10);
      digitalWrite(DIR1, LOW);   //右边
      digitalWrite(DIR2, HIGH);
      digitalWrite(DIR3, HIGH );
      digitalWrite(DIR4, LOW );
      delay(10); 
}

void tingzhi()
{
      
      digitalWrite(PWM1, LOW);   //停止
      digitalWrite(PWM2, LOW);
      digitalWrite(PWM3, LOW );
      digitalWrite(PWM4, LOW );
}*/
