VOID MmProbeAndLockSelectedPages(
  [in, out] PMDL                  MemoryDescriptorList,
  [in]      PFILE_SEGMENT_ELEMENT SegmentArray,
  [in]      KPROCESSOR_MODE       AccessMode,
  [in]      LOCK_OPERATION        Operation
);