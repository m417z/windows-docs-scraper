NTSTATUS IoOpenDriverRegistryKey(
  [in]  PDRIVER_OBJECT     DriverObject,
  [in]  DRIVER_REGKEY_TYPE RegKeyType,
  [in]  ACCESS_MASK        DesiredAccess,
  [in]  ULONG              Flags,
  [out] PHANDLE            DriverRegKey
);