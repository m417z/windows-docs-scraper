NTSTATUS IoGetDeviceInterfacePropertyData(
  [in]  PUNICODE_STRING  SymbolicLinkName,
  [in]  const DEVPROPKEY *PropertyKey,
  [in]  LCID             Lcid,
        ULONG            Flags,
  [in]  ULONG            Size,
  [out] PVOID            Data,
  [out] PULONG           RequiredSize,
  [out] PDEVPROPTYPE     Type
);