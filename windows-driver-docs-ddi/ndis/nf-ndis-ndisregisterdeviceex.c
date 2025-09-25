NDIS_STATUS NdisRegisterDeviceEx(
  [in]  NDIS_HANDLE                    NdisHandle,
  [in]  PNDIS_DEVICE_OBJECT_ATTRIBUTES DeviceObjectAttributes,
  [out] PDEVICE_OBJECT                 *pDeviceObject,
  [out] PNDIS_HANDLE                   NdisDeviceHandle
);