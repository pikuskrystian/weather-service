/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v9.0
processor: LPC55S69
package_id: LPC55S69JBD100
mcu_data: ksdk2_0
processor_version: 9.0.0
functionalGroups:
- name: BOARD_InitPeripherals
  UUID: 4a3fc883-b8e8-4f8c-aa99-5abce5664262
  called_from_default_init: true
  selectedCore: cm33_core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system_54b53072540eeeb8f8e9343e71f28176'
- global_system_definitions:
  - user_definitions: ''
  - user_includes: ''
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"

/***********************************************************************************************************************
 * BOARD_InitPeripherals functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * FLEXCOMM3 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'FLEXCOMM3'
- type: 'flexcomm_spi'
- mode: 'SPI_Polling'
- custom_name_enabled: 'false'
- type_id: 'flexcomm_spi_481dadba00035f986f31ed9ac95af181'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'FLEXCOMM3'
- config_sets:
  - fsl_spi:
    - spi_mode: 'kSPI_Master'
    - clockSource: 'FXCOMFunctionClock'
    - clockSourceFreq: 'BOARD_BootClockPLL150M'
    - spi_master_config:
      - enableLoopback: 'false'
      - enableMaster: 'true'
      - polarity: 'kSPI_ClockPolarityActiveHigh'
      - phase: 'kSPI_ClockPhaseFirstEdge'
      - direction: 'kSPI_MsbFirst'
      - baudRate_Bps: '30000000'
      - dataWidth: 'kSPI_Data8Bits'
      - sselNum: 'kSPI_Ssel0'
      - sselPol_set: ''
      - txWatermark: 'kSPI_TxFifo0'
      - rxWatermark: 'kSPI_RxFifo1'
      - delayConfig:
        - preDelay: '0'
        - postDelay: '0'
        - frameDelay: '0'
        - transferDelay: '0'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const spi_master_config_t FLEXCOMM3_config = {
  .enableLoopback = false,
  .enableMaster = true,
  .polarity = kSPI_ClockPolarityActiveHigh,
  .phase = kSPI_ClockPhaseFirstEdge,
  .direction = kSPI_MsbFirst,
  .baudRate_Bps = 30000000UL,
  .dataWidth = kSPI_Data8Bits,
  .sselNum = kSPI_Ssel0,
  .sselPol = kSPI_SpolActiveAllLow,
  .txWatermark = kSPI_TxFifo0,
  .rxWatermark = kSPI_RxFifo1,
  .delayConfig = {
    .preDelay = 0U,
    .postDelay = 0U,
    .frameDelay = 0U,
    .transferDelay = 0U
  }
};

static void FLEXCOMM3_init(void) {
  RESET_PeripheralReset(kFC3_RST_SHIFT_RSTn);
  /* Initialization function */
  SPI_MasterInit(FLEXCOMM3_PERIPHERAL, &FLEXCOMM3_config, FLEXCOMM3_CLOCK_SOURCE);
}

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void)
{
  /* Initialize components */
  FLEXCOMM3_init();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals();
}
