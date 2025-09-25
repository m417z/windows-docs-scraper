void WriteToHardware(
  [in]           WDF_DEVICE_HWACCESS_TARGET_TYPE Type,
  [in]           WDF_DEVICE_HWACCESS_TARGET_SIZE Size,
  [in]           void                            *Address,
  [in]           SIZE_T                          Value,
  [in, optional] void                            *Buffer,
  [in, optional] ULONG                           Count
);