
void Timer_Init(void)
{
	// For Timer 100ms
	TIM4_DeInit();
	TIM4_TimeBaseInit(TIM4_PRESCALER_128, 125);
	TIM4_ClearFlag(TIM4_FLAG_UPDATE);
	TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
	TIM4_Cmd(ENABLE);
	
	
	// For PWM
	TIM2_DeInit();
	//TIM2_TimeBaseInit(TIM2_PRESCALER_2, 512);		// 15kHz
	//TIM2_TimeBaseInit(TIM2_PRESCALER_1024, 120);		// 130Hz
	TIM2_TimeBaseInit(TIM2_PRESCALER_32, 256);			// 1.95kHz
	
	TIM2_OC1Init(TIM2_OCMODE_PWM1, TIM2_OUTPUTSTATE_ENABLE, 0, TIM2_OCPOLARITY_HIGH);
	TIM2_OC1PreloadConfig(ENABLE);
	TIM2_ARRPreloadConfig(ENABLE);
	
	TIM2_Cmd(ENABLE);
}



void Tick(void)
{
	
	
	TIM4_ClearITPendingBit(TIM4_IT_UPDATE);
}


void Set_PWM(unsigned char Value)
{
	TIM2->CCR1L = Value;
}
