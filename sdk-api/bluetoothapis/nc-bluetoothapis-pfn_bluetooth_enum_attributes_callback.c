PFN_BLUETOOTH_ENUM_ATTRIBUTES_CALLBACK PfnBluetoothEnumAttributesCallback;

BOOL PfnBluetoothEnumAttributesCallback(
  ULONG uAttribId,
  LPBYTE pValueStream,
  ULONG cbStreamSize,
  LPVOID pvParam
)
{...}