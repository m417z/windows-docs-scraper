typedef struct _PEP_ACPI_EXTENDED_ADDRESS {
  PEP_ACPI_RESOURCE_TYPE  Type;
  PEP_ACPI_RESOURCE_FLAGS Flags;
  UCHAR                   ResourceFlags;
  UCHAR                   GeneralFlags;
  UCHAR                   TypeSpecificFlags;
  UCHAR                   RevisionId;
  UCHAR                   Reserved;
  ULONGLONG               Granularity;
  ULONGLONG               MinimumAddress;
  ULONGLONG               MaximumAddress;
  ULONGLONG               TranslationAddress;
  ULONGLONG               AddressLength;
  ULONGLONG               TypeAttribute;
  PUNICODE_STRING         DescriptorName;
} PEP_ACPI_EXTENDED_ADDRESS, *PPEP_ACPI_EXTENDED_ADDRESS;