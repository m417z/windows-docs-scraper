NTSTATUS WdfDeviceCreateDeviceInterface(
  [in]           WDFDEVICE        Device,
  [in]           const GUID       *InterfaceClassGUID,
  [in, optional] PCUNICODE_STRING ReferenceString
);