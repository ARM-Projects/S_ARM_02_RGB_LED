

#include "WatchDogTimer_interface.h"
#include "WatchDogTimer_private.h"
#include "../../STD_LIBRARIES/bit_math.h"

wdt_enu_return_state_t wdt_init(wdt_str_wdt_config_t *ptr_str_wdt_config){
	wdt_enu_return_state_t return_value = WDT_E_OK;
	uint32_t u32_wd_chose;
	uint8_t u8_wd_clock_chose;
	if(ptr_str_wdt_config == NULL){
		return_value = WDT_NULL_PTR;
		
		
	}else{
		switch(ptr_str_wdt_config->enu_wdt_index){
			case WDT_INDEX_0:
					u32_wd_chose = WDT_WDT0_BASE_ADDRESS;
					u8_wd_clock_chose = WDT_R0;
				break;
			
			case WDT_INDEX_1:
					u32_wd_chose = WDT_WDT1_BASE_ADDRESS;
					u8_wd_clock_chose = WDT_R1;
				break;
			
			default:
				return_value = WDT_MAX_INDEX;
				break;
		}
		if(return_value == WDT_E_OK){
			//SET_BIT(HWREG8(WDT_SYS_CONTROL_BASE_ADDRESS+WDT_RCGCWD), u8_wd_clock_chose); 
			(*((volatile uint32_t *)0x400FE600) ) = 1;
			HWREG8(u32_wd_chose+WDTCTL) =  (HWREG8(u32_wd_chose+WDTCTL) & (~(1<<WDT_INTTYPE_INDEX)))|(ptr_str_wdt_config->enu_int_type_state<< WDT_INTTYPE_INDEX);
			
		}
		else{
		
		}
	}
	return return_value;

}
wdt_enu_return_state_t wdt_set_timeout(wdt_str_wdt_config_t *ptr_str_wdt_config, uint32_t *ptr_u32_timeout){
	
	wdt_enu_return_state_t return_value = WDT_E_OK;
	uint32_t u32_wd_chose;
	uint8_t u8_wd_clock_chose;
	if((ptr_str_wdt_config == NULL) || (ptr_u32_timeout == NULL)){
		return_value = WDT_NULL_PTR;
	}else{
		
		switch(ptr_str_wdt_config->enu_wdt_index){
			case WDT_INDEX_0:
					u32_wd_chose = WDT_WDT0_BASE_ADDRESS;
					u8_wd_clock_chose = WDT_R0;
				break;
			
			case WDT_INDEX_1:
					u32_wd_chose = WDT_WDT1_BASE_ADDRESS;
					u8_wd_clock_chose = WDT_R1;
				break;
			
			default:
				return_value = WDT_MAX_INDEX;
				break;
		}
		if(return_value == WDT_E_OK){
			
			double f_tick_time = (((double) 1)/F_CPU);
			uint32_t u32_ticks = (uint32_t)(*ptr_u32_timeout/f_tick_time);
			HWREG8(u32_wd_chose+WDTLOAD) =  u32_ticks;
			
		}
		else{
		
		}
		
	}
	return return_value;
}
wdt_enu_return_state_t wdt_start(wdt_str_wdt_config_t *ptr_str_wdt_config){
	wdt_enu_return_state_t return_value = WDT_E_OK;
	uint32_t u32_wd_chose;
	uint8_t u8_wd_clock_chose;
	if(ptr_str_wdt_config == NULL){
		return_value = WDT_NULL_PTR;
	}else{
		
		switch(ptr_str_wdt_config->enu_wdt_index){
			case WDT_INDEX_0:
					u32_wd_chose = WDT_WDT0_BASE_ADDRESS;
					u8_wd_clock_chose = WDT_R0;
				break;
			
			case WDT_INDEX_1:
					u32_wd_chose = WDT_WDT1_BASE_ADDRESS;
					u8_wd_clock_chose = WDT_R1;
				break;
			
			default:
				return_value = WDT_MAX_INDEX;
				break;
		}
		if(return_value == WDT_E_OK){
			
			HWREG8(u32_wd_chose+WDTCTL) =  (HWREG8(u32_wd_chose+WDTCTL) & (~(1<<WDT_INTEN_INDEX)))|(ptr_str_wdt_config->enu_int_state<< WDT_INTEN_INDEX);
			
		}
		else{
		
		}
		
	}
	return return_value;

}
wdt_enu_return_state_t wdt_stop(wdt_str_wdt_config_t *ptr_str_wdt_config){
	wdt_enu_return_state_t return_value = WDT_E_OK;
	uint32_t u32_wd_chose;
	uint8_t u8_wd_clock_chose;
	if(ptr_str_wdt_config == NULL){
		return_value = WDT_NULL_PTR;
	}else{
		
		switch(ptr_str_wdt_config->enu_wdt_index){
			case WDT_INDEX_0:
					u32_wd_chose = WDT_WDT0_BASE_ADDRESS;
					u8_wd_clock_chose = WDT_R0;
				break;
			
			case WDT_INDEX_1:
					u32_wd_chose = WDT_WDT1_BASE_ADDRESS;
					u8_wd_clock_chose = WDT_R1;
				break;
			
			default:
				return_value = WDT_MAX_INDEX;
				break;
		}
		if(return_value == WDT_E_OK){
			
			CLEAR_BIT(HWREG8(u32_wd_chose+WDTCTL), WDT_INTEN_INDEX);
			
		}
		else{
		
		}
		
	}
	return return_value;

}

wdt_enu_return_state_t wdt_get_wd_value(wdt_str_wdt_config_t *ptr_str_wdt_config, uint32_t *ptr_u32_current_time);
wdt_enu_return_state_t wdt_int_occurred(wdt_str_wdt_config_t *ptr_str_wdt_config, uint8_t *ptr_u8_int_state);
wdt_enu_return_state_t wdt_get_int_state(wdt_str_wdt_config_t *ptr_str_wdt_config);
wdt_enu_return_state_t wdt_deinit(wdt_str_wdt_config_t *ptr_str_wdt_config);







