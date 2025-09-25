typedef enum _NDIS_DEVICE_POWER_STATE {
  NdisDeviceStateUnspecified,
  NdisDeviceStateD0,
  NdisDeviceStateD1,
  NdisDeviceStateD2,
  NdisDeviceStateD3,
  NdisDeviceStateMaximum
} NDIS_DEVICE_POWER_STATE, *PNDIS_DEVICE_POWER_STATE;