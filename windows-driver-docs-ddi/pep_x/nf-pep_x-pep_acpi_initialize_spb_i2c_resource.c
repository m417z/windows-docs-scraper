VOID PEP_ACPI_INITIALIZE_SPB_I2C_RESOURCE(
  [in]  USHORT             SlaveAddress,
  [in]  BOOLEAN            DeviceInitiated,
  [in]  ULONG              ConnectionSpeed,
  [in]  BOOLEAN            AddressingMode,
  [in]  PUNICODE_STRING    ResourceSource,
  [in]  UCHAR              ResourceSourceIndex,
  [in]  BOOLEAN            ResourceUsage,
  [in]  BOOLEAN            SharedMode,
  [in]  PCHAR              VendorData,
  [in]  USHORT             VendorDataLength,
  [out] PPEP_ACPI_RESOURCE Resource
);