VOID PEP_ACPI_INITIALIZE_SPB_SPI_RESOURCE(
  [in]  USHORT             DeviceSelection,
  [in]  UCHAR              DeviceSelectionPolarity,
  [in]  UCHAR              WireMode,
  [in]  UCHAR              DataBitLength,
  [in]  BOOLEAN            SlaveMode,
  [in]  ULONG              ConnectionSpeed,
  [in]  UCHAR              ClockPolarity,
  [in]  UCHAR              ClockPhase,
  [in]  PUNICODE_STRING    ResourceSource,
  [in]  UCHAR              ResourceSourceIndex,
  [in]  BOOLEAN            ResourceUsage,
  [in]  BOOLEAN            SharedMode,
  [in]  PCHAR              VendorData,
  [in]  USHORT             VendorDataLength,
  [out] PPEP_ACPI_RESOURCE Resource
);