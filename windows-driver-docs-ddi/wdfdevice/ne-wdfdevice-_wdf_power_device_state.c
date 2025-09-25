typedef enum _WDF_POWER_DEVICE_STATE {
  WdfPowerDeviceInvalid = 0,
  WdfPowerDeviceD0,
  WdfPowerDeviceD1,
  WdfPowerDeviceD2,
  WdfPowerDeviceD3,
  WdfPowerDeviceD3Final,
  WdfPowerDevicePrepareForHibernation,
  WdfPowerDeviceMaximum
} WDF_POWER_DEVICE_STATE, *PWDF_POWER_DEVICE_STATE;