NTSTATUS WdfDeviceAllocAndQueryInterfaceProperty(
  [in]           WDFDEVICE                           Device,
  [in]           PWDF_DEVICE_INTERFACE_PROPERTY_DATA PropertyData,
  [in]           POOL_TYPE                           PoolType,
  [in, optional] PWDF_OBJECT_ATTRIBUTES              PropertyMemoryAttributes,
  [out]          WDFMEMORY                           *PropertyMemory,
  [out]          PDEVPROPTYPE                        Type
);