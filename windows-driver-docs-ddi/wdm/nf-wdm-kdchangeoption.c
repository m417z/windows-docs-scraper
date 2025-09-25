NTSTATUS KdChangeOption(
  [in]            KD_OPTION Option,
  [in, optional]  ULONG     InBufferBytes,
  [in]            PVOID     InBuffer,
  [in, optional]  ULONG     OutBufferBytes,
  [out]           PVOID     OutBuffer,
  [out, optional] PULONG    OutBufferNeeded
);