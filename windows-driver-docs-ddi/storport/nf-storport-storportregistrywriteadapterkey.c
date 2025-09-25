ULONG StorPortRegistryWriteAdapterKey(
  [in]           PVOID  HwDeviceExtension,
  [in, optional] PUCHAR SubKeyName,
  [in]           PUCHAR ValueName,
  [in]           ULONG  ValueType,
  [in, out]      PVOID  ValueData,
  [in, out]      ULONG  ValueDataLength
);