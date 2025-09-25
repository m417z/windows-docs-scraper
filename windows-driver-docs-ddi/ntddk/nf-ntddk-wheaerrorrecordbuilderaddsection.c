PVOID WheaErrorRecordBuilderAddSection(
  [in, out]           PWHEA_ERROR_RECORD                         Record,
  [in]                UINT32                                     MaxSectionCount,
  [in]                UINT32                                     SectionLength,
  [in]                WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_FLAGS Flags,
  [in]                GUID                                       SectionType,
  [in, out, optional] PVOID                                      DescriptorOut
);