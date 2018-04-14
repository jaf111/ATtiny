 #include <avr/io.h>

void adc_init(){

	ADC0.CTRLA |= (ADC_RESSEL_8BIT_gc);
	ADC0.CTRLB |= (0x03);
	ADC0.CTRLC |= (ADC_REFSEL_VDDREF_gc);
	ADC0.CTRLC |= (ADC_PRESC_DIV64_gc);
	ADC0.MUXPOS |= (ADC_MUXPOS0_bm);
	ADC0.CTRLA |= (ADC_ENABLE_bm);
		
}

uint8_t adc_read(uint8_t channel){

	ADC0.MUXPOS = channel;	
	ADC0.COMMAND |= (ADC_STCONV_bm);
	while(ADC0.INTFLAGS != ADC_RESRDY_bm){}
		
	int data= ADC0.RESL;
	ADC0.INTFLAGS &= ~(ADC_RESRDY_bm);
	return data; 

}
