NTSTATUS IoRegisterDeviceInterface(
  [in]           PDEVICE_OBJECT  PhysicalDeviceObject,
  [in]           const GUID      *InterfaceClassGuid,
  [in, optional] PUNICODE_STRING ReferenceString,
  [out]          PUNICODE_STRING SymbolicLinkName
);