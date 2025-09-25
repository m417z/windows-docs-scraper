typedef struct _PEP_ACPI_REQUEST_CONVERT_TO_BIOS_RESOURCES {
  NTSTATUS           TranslationStatus;
  PPEP_ACPI_RESOURCE InputBuffer;
  SIZE_T             InputBufferSize;
  PVOID              OutputBuffer;
  SIZE_T             OutputBufferSize;
  ULONG              Flags;
} PEP_ACPI_REQUEST_CONVERT_TO_BIOS_RESOURCES, *PPEP_ACPI_REQUEST_CONVERT_TO_BIOS_RESOURCES;