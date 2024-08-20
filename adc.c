void ADC_Init(void)
{
	ADC1_DeInit();
		ADC1_Init(ADC1_CONVERSIONMODE_SINGLE,
             ADC1_CHANNEL_4,
             ADC1_PRESSEL_FCPU_D18,
             ADC1_EXTTRIG_TIM,
             DISABLE,
             ADC1_ALIGN_RIGHT,
             ADC1_SCHMITTTRIG_ALL,
             DISABLE);
		
		ADC1_Cmd(ENABLE);
}


void Get_ADC()
{
  // Get ADC 10-bit
	ADC1_StartConversion();
	while(ADC1_GetFlagStatus(ADC1_FLAG_EOC) == FALSE);
	_ADC_Raw = ADC1_GetConversionValue();
	ADC1_ClearFlag(ADC1_FLAG_EOC);
}
