pHalQuerySystemInformation Phalquerysysteminformation;

NTSTATUS Phalquerysysteminformation(
  [in]  HAL_QUERY_INFORMATION_CLASS InformationClass,
  [in]  ULONG BufferSize,
  [out] PVOID Buffer,
  [out] PULONG ReturnedLength
)
{...}