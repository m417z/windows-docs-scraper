VOID CcCoherencyFlushAndPurgeCache(
  [in]           PSECTION_OBJECT_POINTERS SectionObjectPointer,
  [in, optional] PLARGE_INTEGER           FileOffset,
  [in]           ULONG                    Length,
  [out]          PIO_STATUS_BLOCK         IoStatus,
  [in, optional] ULONG                    Flags
);