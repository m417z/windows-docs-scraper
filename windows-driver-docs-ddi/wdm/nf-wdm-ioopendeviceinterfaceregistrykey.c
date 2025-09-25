NTSTATUS IoOpenDeviceInterfaceRegistryKey(
  [in]  PUNICODE_STRING SymbolicLinkName,
  [in]  ACCESS_MASK     DesiredAccess,
  [out] PHANDLE         DeviceInterfaceRegKey
);