NTSTATUS IoGetDevicePropertyData(
  [in]  PDEVICE_OBJECT   Pdo,
  [in]  const DEVPROPKEY *PropertyKey,
  [in]  LCID             Lcid,
        ULONG            Flags,
  [in]  ULONG            Size,
  [out] PVOID            Data,
  [out] PULONG           RequiredSize,
  [out] PDEVPROPTYPE     Type
);