SRIOV_READ_CONFIG SriovReadConfig;

NTSTATUS SriovReadConfig(
  [in]  PVOID Context,
  [out] PVOID Data,
  [in]  USHORT VfIndex,
  [in]  ULONG Offset,
  [in]  ULONG Length
)
{...}