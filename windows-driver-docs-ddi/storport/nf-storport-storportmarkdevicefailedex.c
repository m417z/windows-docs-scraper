ULONG StorPortMarkDeviceFailedEx(
  PVOID         HwDeviceExtension,
  PSTOR_ADDRESS StorAddress,
  ULONG         Flags,
  USHORT        FaultCode,
  PWSTR         FaultDescription,
  USHORT        AdditionalDataSize,
  PUCHAR        AdditionalData,
  USHORT        CriticalDataSize,
  PUCHAR        CriticalData
);