typedef enum _USBC_CHARGING_STATE {
  UsbCChargingStateInvalid,
  UsbCChargingStateNotCharging,
  UsbCChargingStateNominalCharging,
  UsbCChargingStateSlowCharging,
  UsbCChargingStateTrickleCharging
} USBC_CHARGING_STATE;