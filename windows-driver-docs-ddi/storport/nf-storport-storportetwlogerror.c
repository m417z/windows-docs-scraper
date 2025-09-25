ULONG StorPortEtwLogError(
  [in]           PVOID         HwDeviceExtension,
  [in, optional] PSTOR_ADDRESS Address,
  [in]           ULONG         Id,
  [in]           PWSTR         Description,
  [in]           ULONG         DataBufferLength,
  [in]           PVOID         DataBuffer
);