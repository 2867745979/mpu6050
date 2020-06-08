#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "mpu6050.h"  
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 

int main(void)
{

	float pitch,roll,yaw; 		//ŷ����

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
	delay_init();	//��ʱ��ʼ�� 
	LED_Init();		  			//��ʼ����LED���ӵ�Ӳ���ӿ�
	MPU_Init();					//��ʼ��MPU6050

	while(mpu_dmp_init())
	{
	delay_ms(20);
	}

	while(1)
	{
		delay_ms(2);
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		{
			LED=~LED;
		}
		printf("%f,%f,%f\r\n",pitch,roll,yaw);
	} 	
}
 


