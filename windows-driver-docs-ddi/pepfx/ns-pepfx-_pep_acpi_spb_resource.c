typedef struct _PEP_ACPI_SPB_RESOURCE {
  PEP_ACPI_RESOURCE_TYPE  Type;
  PEP_ACPI_RESOURCE_FLAGS Flags;
  USHORT                  TypeSpecificFlags;
  UCHAR                   ResourceSourceIndex;
  PUNICODE_STRING         ResourceSourceName;
  PCHAR                   VendorData;
  USHORT                  VendorDataLength;
} PEP_ACPI_SPB_RESOURCE, *PPEP_ACPI_SPB_RESOURCE;