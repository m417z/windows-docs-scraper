SIZE_T ReadFromHardware(
  [in]           WDF_DEVICE_HWACCESS_TARGET_TYPE Type,
  [in]           WDF_DEVICE_HWACCESS_TARGET_SIZE Size,
  [in]           void                            *Address,
  [out]          void                            *Buffer,
  [in, optional] ULONG                           Count
);