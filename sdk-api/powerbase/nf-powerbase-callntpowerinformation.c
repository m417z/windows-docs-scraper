NTSTATUS CallNtPowerInformation(
  [in]  POWER_INFORMATION_LEVEL InformationLevel,
  [in]  PVOID                   InputBuffer,
  [in]  ULONG                   InputBufferLength,
  [out] PVOID                   OutputBuffer,
  [in]  ULONG                   OutputBufferLength
);