VOID MmProbeAndLockPages(
  [in, out] PMDL            MemoryDescriptorList,
  [in]      KPROCESSOR_MODE AccessMode,
  [in]      LOCK_OPERATION  Operation
);