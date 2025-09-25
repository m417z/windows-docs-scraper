VOID PEP_ACPI_INITIALIZE_GPIO_IO_RESOURCE(
  [in]  BOOLEAN                     Shareable,
  [in]  BOOLEAN                     CanWake,
  [in]  GPIO_PIN_CONFIG_TYPE        PinConfig,
  [in]  USHORT                      DebounceTimeout,
  [in]  USHORT                      DriveStrength,
  [in]  GPIO_PIN_IORESTRICTION_TYPE IoRestriction,
  [in]  UCHAR                       ResourceSourceIndex,
  [in]  PUNICODE_STRING             ResourceSourceName,
  [in]  BOOLEAN                     ResourceUsage,
  [in]  PUCHAR                      VendorData,
  [in]  USHORT                      VendorDataLength,
  [in]  PUSHORT                     PinTable,
  [in]  USHORT                      PinCount,
  [out] PPEP_ACPI_RESOURCE          Resource
);