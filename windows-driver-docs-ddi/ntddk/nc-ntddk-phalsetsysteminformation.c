pHalSetSystemInformation Phalsetsysteminformation;

NTSTATUS Phalsetsysteminformation(
  [in]  HAL_SET_INFORMATION_CLASS InformationClass,
  [in]  ULONG BufferSize,
  [out] PVOID Buffer
)
{...}