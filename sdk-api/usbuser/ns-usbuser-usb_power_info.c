typedef struct _USB_POWER_INFO {
  WDMUSB_POWER_STATE SystemState;
  WDMUSB_POWER_STATE HcDevicePowerState;
  WDMUSB_POWER_STATE HcDeviceWake;
  WDMUSB_POWER_STATE HcSystemWake;
  WDMUSB_POWER_STATE RhDevicePowerState;
  WDMUSB_POWER_STATE RhDeviceWake;
  WDMUSB_POWER_STATE RhSystemWake;
  WDMUSB_POWER_STATE LastSystemSleepState;
  BOOLEAN            CanWakeup;
  BOOLEAN            IsPowered;
} USB_POWER_INFO, *PUSB_POWER_INFO;