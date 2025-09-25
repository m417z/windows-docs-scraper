BOOL BluetoothSdpEnumAttributes(
  LPBYTE                                 pSDPStream,
  ULONG                                  cbStreamSize,
  PFN_BLUETOOTH_ENUM_ATTRIBUTES_CALLBACK pfnCallback,
  LPVOID                                 pvParam
);