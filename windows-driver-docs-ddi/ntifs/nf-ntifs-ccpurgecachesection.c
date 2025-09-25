BOOLEAN CcPurgeCacheSection(
  [in]           PSECTION_OBJECT_POINTERS SectionObjectPointer,
  [in, optional] PLARGE_INTEGER           FileOffset,
  [in]           ULONG                    Length,
                 ULONG                    Flags
);