VOID PEP_ACPI_INITIALIZE_GPIO_INT_RESOURCE(
  [in]  KINTERRUPT_MODE      InterruptType,
  [in]  KINTERRUPT_POLARITY  LevelType,
  [in]  BOOLEAN              Shareable,
  [in]  BOOLEAN              CanWake,
  [in]  GPIO_PIN_CONFIG_TYPE PinConfig,
  [in]  USHORT               DebounceTimeout,
  [in]  UCHAR                ResourceSourceIndex,
  [in]  PUNICODE_STRING      ResourceSourceName,
  [in]  BOOLEAN              ResourceUsage,
  [in]  PUCHAR               VendorData,
  [in]  USHORT               VendorDataLength,
  [in]  PUSHORT              PinTable,
  [in]  UCHAR                PinCount,
  [out] PPEP_ACPI_RESOURCE   Resource
);