NTSTATUS WheaFindErrorRecordSection(
  [in]            PWHEA_ERROR_RECORD                    Record,
  [in]            const GUID                            *SectionType,
  [out]           PWHEA_ERROR_RECORD_SECTION_DESCRIPTOR *SectionDescriptor,
  [out, optional] PVOID                                 *SectionData
);