#ifndef WATCH_DOG_TIMER_H
#define WATCH_DOG_TIMER_H

#include "../../STD_LIBRARIES/STD_TYPES.h"


#define F_CPU						160000000 
typedef enum{
	WDT_E_NOT_OK = 0,
	WDT_E_OK,
	WDT_NULL_PTR,	
	WDT_MAX_INDEX
}wdt_enu_return_state_t;

typedef enum{
	WDT_INDEX_0 = 0,
	WDT_INDEX_1	
}wdt_enu_wdt_index_t;

typedef enum{
	WDT_INT_DISABLE = 0,
	WDT_INT_ENABLE
}wdt_enu_int_state_t;

typedef enum{
	WDT_RESET_DISABLE = 0,
	WDT_RESET_ENABLE,
}wdt_enu_reset_state_t;

typedef enum{
	WDT_INT_STANDARD = 0,
	WDT_RESET_NMI,
}wdt_enu_int_type_state_t;

/*typedef enum{
	WDT_INT_STANDARD = 0,
	WDT_RESET_NMI,
}wdt_enu_int_type_state_t;*/

typedef struct{
	wdt_enu_wdt_index_t enu_wdt_index;
	wdt_enu_int_state_t enu_int_state;
	wdt_enu_reset_state_t enu_reset_state;
	wdt_enu_int_type_state_t enu_int_type_state;
	
}wdt_str_wdt_config_t;



wdt_enu_return_state_t wdt_init(wdt_str_wdt_config_t *ptr_str_wdt_config);
wdt_enu_return_state_t wdt_set_timeout(wdt_str_wdt_config_t *ptr_str_wdt_config, uint32_t *ptr_u32_timeout);
wdt_enu_return_state_t wdt_start(wdt_str_wdt_config_t *ptr_str_wdt_config);
wdt_enu_return_state_t wdt_stop(wdt_str_wdt_config_t *ptr_str_wdt_config);
wdt_enu_return_state_t wdt_get_wd_value(wdt_str_wdt_config_t *ptr_str_wdt_config, uint32_t *ptr_u32_current_time);
wdt_enu_return_state_t wdt_int_occurred(wdt_str_wdt_config_t *ptr_str_wdt_config, uint8_t *ptr_u8_int_state);
wdt_enu_return_state_t wdt_deinit(wdt_str_wdt_config_t *ptr_str_wdt_config);
#endif