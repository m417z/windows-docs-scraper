typedef enum _WDMUSB_POWER_STATE {
  WdmUsbPowerNotMapped = 0,
  WdmUsbPowerSystemUnspecified = 100,
  WdmUsbPowerSystemWorking,
  WdmUsbPowerSystemSleeping1,
  WdmUsbPowerSystemSleeping2,
  WdmUsbPowerSystemSleeping3,
  WdmUsbPowerSystemHibernate,
  WdmUsbPowerSystemShutdown,
  WdmUsbPowerDeviceUnspecified = 200,
  WdmUsbPowerDeviceD0,
  WdmUsbPowerDeviceD1,
  WdmUsbPowerDeviceD2,
  WdmUsbPowerDeviceD3
} WDMUSB_POWER_STATE;