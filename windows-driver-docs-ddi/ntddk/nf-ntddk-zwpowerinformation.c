NTSYSAPI NTSTATUS ZwPowerInformation(
  [in]            POWER_INFORMATION_LEVEL InformationLevel,
  [in, optional]  PVOID                   InputBuffer,
  [in]            ULONG                   InputBufferLength,
  [out, optional] PVOID                   OutputBuffer,
  [in]            ULONG                   OutputBufferLength
);