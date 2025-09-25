VOID PEP_ACPI_INITIALIZE_EXTENDED_IO_RESOURCE(
  [in]  BOOLEAN            ResourceUsage,
  [in]  UCHAR              Decode,
  [in]  BOOLEAN            IsMinFixed,
  [in]  BOOLEAN            IsMaxFixed,
  [in]  UCHAR              ISARanges,
  [in]  ULONGLONG          AddressGranularity,
  [in]  ULONGLONG          AddressMinimum,
  [in]  ULONGLONG          AddressMaximum,
  [in]  ULONGLONG          AddressTranslation,
  [in]  ULONGLONG          RangeLength,
  [in]  ULONGLONG          TypeSpecificAttributes,
  [in]  PUNICODE_STRING    DescriptorName,
  [in]  BOOLEAN            TranslationTypeNonStatic,
  [in]  BOOLEAN            TanslationSparseDensity,
  [out] PPEP_ACPI_RESOURCE Resource
);