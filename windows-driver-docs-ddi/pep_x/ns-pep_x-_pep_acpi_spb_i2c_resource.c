typedef struct _PEP_ACPI_SPB_I2C_RESOURCE {
  PEP_ACPI_SPB_RESOURCE SpbCommon;
  ULONG                 ConnectionSpeed;
  USHORT                SlaveAddress;
} PEP_ACPI_SPB_I2C_RESOURCE, *PPEP_ACPI_SPB_I2C_RESOURCE;