NTSTATUS WdfDeviceAllocAndQueryPropertyEx(
  [in]           WDFDEVICE                 Device,
  [in]           PWDF_DEVICE_PROPERTY_DATA DeviceProperty,
  [in]           POOL_TYPE                 PoolType,
  [in, optional] PWDF_OBJECT_ATTRIBUTES    PropertyMemoryAttributes,
  [out]          WDFMEMORY                 *PropertyMemory,
  [out]          PDEVPROPTYPE              Type
);