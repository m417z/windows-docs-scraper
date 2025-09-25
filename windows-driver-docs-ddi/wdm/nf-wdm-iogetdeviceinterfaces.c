NTSTATUS IoGetDeviceInterfaces(
  [in]           const GUID     *InterfaceClassGuid,
  [in, optional] PDEVICE_OBJECT PhysicalDeviceObject,
  [in]           ULONG          Flags,
  [out]          PZZWSTR        *SymbolicLinkList
);