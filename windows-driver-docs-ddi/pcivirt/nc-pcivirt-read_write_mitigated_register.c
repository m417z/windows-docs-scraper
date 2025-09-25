READ_WRITE_MITIGATED_REGISTER ReadWriteMitigatedRegister;

NTSTATUS ReadWriteMitigatedRegister(
  [in]      PVOID Context,
  [in]      USHORT VfIndex,
  [in]      BOOLEAN Read,
  [in]      USHORT BarIndex,
  [in]      ULONGLONG Offset,
  [in]      ULONG Length,
  [in, out] PUCHAR Data
)
{...}