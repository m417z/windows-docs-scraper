VOID CcFlushCache(
  [in]            PSECTION_OBJECT_POINTERS SectionObjectPointer,
  [in, optional]  PLARGE_INTEGER           FileOffset,
  [in]            ULONG                    Length,
  [out, optional] PIO_STATUS_BLOCK         IoStatus
);