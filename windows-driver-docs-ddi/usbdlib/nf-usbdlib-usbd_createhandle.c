NTSTATUS USBD_CreateHandle(
  [in]  PDEVICE_OBJECT DeviceObject,
  [in]  PDEVICE_OBJECT TargetDeviceObject,
  [in]  ULONG          USBDClientContractVersion,
  [in]  ULONG          PoolTag,
  [out] USBD_HANDLE    *USBDHandle
);