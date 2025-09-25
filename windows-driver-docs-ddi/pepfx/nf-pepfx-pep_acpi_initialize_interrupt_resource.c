VOID PEP_ACPI_INITIALIZE_INTERRUPT_RESOURCE(
  [in]  BOOLEAN             ResourceUsage,
  [in]  KINTERRUPT_MODE     EdgeLevel,
  [in]  KINTERRUPT_POLARITY InterruptLevel,
  [in]  BOOLEAN             ShareType,
  [in]  BOOLEAN             Wake,
  [in]  PULONG              PinTable,
  [in]  UCHAR               PinCount,
  [out] PPEP_ACPI_RESOURCE  Resource
);