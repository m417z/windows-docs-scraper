VOID WdfDeviceWriteToHardware(
  [in]           WDFDEVICE                       Device,
  [in]           WDF_DEVICE_HWACCESS_TARGET_TYPE Type,
  [in]           WDF_DEVICE_HWACCESS_TARGET_SIZE Size,
  [in]           PVOID                           TargetAddress,
  [in]           SIZE_T                          Value,
  [in, optional] PVOID                           Buffer,
  [in, optional] ULONG                           Count
);