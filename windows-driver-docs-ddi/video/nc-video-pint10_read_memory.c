PINT10_READ_MEMORY Pint10ReadMemory;

VP_STATUS Pint10ReadMemory(
  [in]  IN PVOID Context,
  [in]  IN USHORT Seg,
  [in]  IN USHORT Off,
  [out] OUT PVOID Buffer,
  [in]  IN ULONG Length
)
{...}