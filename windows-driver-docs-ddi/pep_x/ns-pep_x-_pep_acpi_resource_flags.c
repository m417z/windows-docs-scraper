typedef union _PEP_ACPI_RESOURCE_FLAGS {
  ULONG  AsULong;
  struct {
    ULONG Shared : 1;
    ULONG Wake : 1;
    ULONG ResourceUsage : 1;
    ULONG SlaveMode : 1;
    ULONG AddressingMode : 1;
    ULONG SharedMode : 1;
    ULONG Reserved : 26;
  } DUMMYSTRUCTNAME;
} PEP_ACPI_RESOURCE_FLAGS, *PPEP_ACPI_RESOURCE_FLAGS;