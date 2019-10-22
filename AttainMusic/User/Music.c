#include "Music.h"
#include "tim.h"
#include "gpio.h"


/*����Ƶ�ʱ�A~G���߸�����Ӧ ��H:�� M:�� L:�ͣ��ģ�Do Re Mi Fa Sol La Si��*/
const int Frequency[][21] =
{  
/*Do   Re   Mi   Fa   Sol  La   Si   Do   Re   Mi   Fa   Sol  La   Si   Do   Re    Mi    Fa    Sol   La    Si*/
	221, 248, 278, 294, 330, 371, 416, 441, 495, 556, 589, 661, 742, 833, 882, 990 , 1112, 1178, 1322, 1484, 1665, /* A */
	248, 278, 294, 330, 371, 416, 467, 495, 556, 589, 661, 742, 833, 935, 990, 1112, 1178, 1322, 1484, 1665, 1869, /* B */
	131, 147, 165, 175, 196, 221, 248, 262, 294, 330, 350, 393, 441, 495, 525, 589 , 661 , 700 , 786 , 882 , 990 , /* C */
	147, 165, 175, 196, 221, 248, 278, 294, 330, 350, 393, 441, 495, 556, 589, 661 , 700 , 786 , 882 , 990 , 1112, /* D */
	165, 175, 196, 221, 248, 278, 312, 330, 350, 393, 441, 495, 556, 624, 661, 700 , 786 , 882 , 990 , 1112, 1248, /* E */
	175, 196, 221, 234, 262, 294, 330, 350, 393, 441, 495, 556, 624, 661, 700, 786 , 882 , 935 , 1049, 1178, 1322, /* F */
	196, 221, 234, 262, 294, 330, 371, 393, 441, 495, 556, 624, 661, 742, 786, 882 , 990 , 1049, 1178, 1322, 1484  /* G */
/*L1   L2   L3   L4   L5   L6   L7   M1   M2   M3   M4   M5   M6   M7   H1   H2    H3    H4    H5    H6    H7 */
}; 

/**
* @brief   ���ֲ��ź���
* @param   *MusicScore �����ף�Lenght �����״�С��Tone ��������A~G��
* @retval  void
*/
void PlayMusic(const int *MusicScore, int Lenght, int Tune)
{
	int arr = 0;
	
	if(HAL_GPIO_ReadPin(KEY_GPIO_Port, KEY_Pin))/*�������¿�ʼ����*/
	{	
	  HAL_Delay(3000);
		for(int i=0; i < Lenght/2; i++)
		{
			/*��װ��ֵ = ��Ƶ���ʱ��Ƶ��/���׶�Ӧ��Ƶ��(���)*/
			arr = FREQUENCY/Frequency[Tune][MusicScore[i*2]] - 1;
			
			TIM12->ARR = arr;
			TIM12->CCR1 = arr/50;/*ռ�ձ�1/20,ռ�ձ�ԽС������ԽС*/
			
			HAL_Delay(MusicScore[2*i + 1]);

			HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin);
			HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin);
			GPIOG->ODR^=1<<(1+(MusicScore[i*2])%7); /*��Ӧ�ĵ���˸*/

			TIM12->CCR1 = 0;
  	  HAL_Delay(1);
		}		
	}
	else
	{
			TIM12->CCR1 = 0;
	}
}



