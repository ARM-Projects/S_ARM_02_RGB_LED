#include "SYSTICK_private.h"
#include "SYSTICK_interface.h"

#include "../../STD_LIBRARIES/STD_TYPES.h"
#include "../../STD_LIBRARIES/bit_math.h"



systick_enu_return_state_t  systick_init(systick_str_systick_config_t *ptr_str_systick_config){
	systick_enu_return_state_t return_value = SYSTICK_OK;

	
	
    if( ptr_str_systick_config != NULL){
			
			STK_CTRL = (STK_CTRL & (~(1<<STK_CLKSOURCE)))| ptr_str_systick_config->enu_clock_source<<STK_CLKSOURCE;
			
			
		}else{
			return_value = SYSTICK_NULL_PTR;
		}
		return 	return_value;

}
systick_enu_return_state_t  systick_set_timeout_ms(uint32_t time_out){
	systick_enu_return_state_t return_value = SYSTICK_OK;

    if(time_out <16777216){
				//read clock source
				//calculate ticks
				//set load registers
		}else{
			return_value = SYSTICK_NULL_PTR;
		}
		return 	return_value;
}
systick_enu_return_state_t  systick_set_callback(ptr_void_func ptr_callback_func);
systick_enu_return_state_t  systick_counter_enable(systick_str_systick_config_t *ptr_str_systick_config);
systick_enu_return_state_t  systick_counter_disable(systick_str_systick_config_t *ptr_str_systick_config);
systick_enu_return_state_t  systick_get_state(systick_str_systick_config_t *ptr_str_systick_config);