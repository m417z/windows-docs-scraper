NDIS_STATUS NdisMRegisterDevice(
  [in]  NDIS_HANDLE      NdisWrapperHandle,
  [in]  PNDIS_STRING     DeviceName,
  [in]  PNDIS_STRING     SymbolicName,
  [in]  PDRIVER_DISPATCH *MajorFunctions,
  [in]  PDEVICE_OBJECT   *pDeviceObject,
  [out] NDIS_HANDLE      *NdisDeviceHandle
);