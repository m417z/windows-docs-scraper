NTSTATUS IoSetDeviceInterfacePropertyData(
  [in]           PUNICODE_STRING  SymbolicLinkName,
  [in]           const DEVPROPKEY *PropertyKey,
  [in]           LCID             Lcid,
  [in]           ULONG            Flags,
  [in]           DEVPROPTYPE      Type,
  [in]           ULONG            Size,
  [in, optional] PVOID            Data
);