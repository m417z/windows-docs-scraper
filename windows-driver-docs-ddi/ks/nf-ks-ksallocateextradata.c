KSDDKAPI NTSTATUS KsAllocateExtraData(
  [in, out] PIRP  Irp,
  [in]      ULONG ExtraSize,
  [out]     PVOID *ExtraBuffer
);