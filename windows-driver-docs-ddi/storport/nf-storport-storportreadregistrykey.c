ULONG StorPortReadRegistryKey(
  PVOID  HwDeviceExtension,
  PWSTR  AbsolutePath,
  PWSTR  KeyName,
  ULONG  ValueType,
  PVOID  *ValueData,
  PULONG ValueDataLength
);