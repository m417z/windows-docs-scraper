VOID PEP_ACPI_INITIALIZE_EXTENDED_MEMORY_RESOURCE(
  [in]  BOOLEAN            ResourceUsage,
  [in]  UCHAR              Decode,
  [in]  BOOLEAN            IsMinFixed,
  [in]  BOOLEAN            IsMaxFixed,
  [in]  UCHAR              Cacheable,
  [in]  BOOLEAN            ReadWrite,
  [in]  ULONGLONG          AddressGranularity,
  [in]  ULONGLONG          AddressMinimum,
  [in]  ULONGLONG          AddressMaximum,
  [in]  ULONGLONG          AddressTranslation,
  [in]  ULONGLONG          RangeLength,
  [in]  ULONGLONG          TypeSpecificAttributes,
  [in]  PUNICODE_STRING    DescriptorName,
  [in]  UCHAR              MemoryRangeType,
        BOOLEAN            TranslationTypeNonStatic,
  [out] PPEP_ACPI_RESOURCE Resource
);