NTSTATUS WdfFdoInitAllocAndQueryProperty(
  [in]           PWDFDEVICE_INIT          DeviceInit,
  [in]           DEVICE_REGISTRY_PROPERTY DeviceProperty,
  [in]           POOL_TYPE                PoolType,
  [in, optional] PWDF_OBJECT_ATTRIBUTES   PropertyMemoryAttributes,
  [out]          WDFMEMORY                *PropertyMemory
);