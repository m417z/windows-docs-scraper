PVOID FLTAPI FltAllocatePoolAlignedWithTag(
  [in] PFLT_INSTANCE Instance,
  [in] POOL_TYPE     PoolType,
  [in] SIZE_T        NumberOfBytes,
  [in] ULONG         Tag
);