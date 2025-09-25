ULONG StorPortRegistryReadAdapterKey(
  [in]           PVOID  HwDeviceExtension,
  [in, optional] PUCHAR SubKeyName,
  [in]           PUCHAR ValueName,
  [in]           ULONG  ValueType,
  [in, out]      PVOID  *ValueData,
  [in, out]      PULONG ValueDataLength
);