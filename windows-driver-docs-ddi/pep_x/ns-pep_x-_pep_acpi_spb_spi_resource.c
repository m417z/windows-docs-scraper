typedef struct _PEP_ACPI_SPB_SPI_RESOURCE {
  PEP_ACPI_SPB_RESOURCE SpbCommon;
  ULONG                 ConnectionSpeed;
  UCHAR                 DataBitLength;
  UCHAR                 Phase;
  UCHAR                 Polarity;
  USHORT                DeviceSelection;
} PEP_ACPI_SPB_SPI_RESOURCE, *PPEP_ACPI_SPB_SPI_RESOURCE;