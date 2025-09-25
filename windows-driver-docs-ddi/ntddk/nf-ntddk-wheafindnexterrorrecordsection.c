NTSTATUS WheaFindNextErrorRecordSection(
  [in]            PWHEA_ERROR_RECORD                    Record,
  [in, out]       ULONG                                 *Context,
  [out]           PWHEA_ERROR_RECORD_SECTION_DESCRIPTOR *SectionDescriptor,
  [out, optional] PVOID                                 *SectionData
);