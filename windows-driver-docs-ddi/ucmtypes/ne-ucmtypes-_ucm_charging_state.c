typedef enum _UCM_CHARGING_STATE {
  UcmChargingStateInvalid,
  UcmChargingStateNotCharging,
  UcmChargingStateNominalCharging,
  UcmChargingStateSlowCharging,
  UcmChargingStateTrickleCharging
} UCM_CHARGING_STATE, *PUCM_CHARGING_STATE;