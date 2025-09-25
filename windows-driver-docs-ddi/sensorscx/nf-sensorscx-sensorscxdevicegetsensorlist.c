NTSTATUS SensorsCxDeviceGetSensorList(
  [in]      WDFDEVICE    FxDevice,
  [out]     SENSOROBJECT *pSensorList,
  [in, out] PULONG       pListCount
);