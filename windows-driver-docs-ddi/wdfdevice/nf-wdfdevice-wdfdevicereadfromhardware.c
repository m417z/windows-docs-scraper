SIZE_T WdfDeviceReadFromHardware(
  [in]            WDFDEVICE                       Device,
  [in]            WDF_DEVICE_HWACCESS_TARGET_TYPE Type,
  [in]            WDF_DEVICE_HWACCESS_TARGET_SIZE Size,
  [in]            PVOID                           TargetAddress,
  [out, optional] PVOID                           Buffer,
  [in, optional]  ULONG                           Count
);