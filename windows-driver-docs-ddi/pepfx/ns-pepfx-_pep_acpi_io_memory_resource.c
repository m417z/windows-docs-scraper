typedef struct _PEP_ACPI_IO_MEMORY_RESOURCE {
  PEP_ACPI_RESOURCE_TYPE Type;
  UCHAR                  Information;
  PHYSICAL_ADDRESS       MinimumAddress;
  PHYSICAL_ADDRESS       MaximumAddress;
  ULONG                  Alignment;
  ULONG                  Length;
} PEP_ACPI_IO_MEMORY_RESOURCE, *PPEP_ACPI_IO_MEMORY_RESOURCE;