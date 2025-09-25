NTSTATUS WdfDeviceRetrieveDeviceInterfaceString(
  [in]           WDFDEVICE        Device,
  [in]           const GUID       *InterfaceClassGUID,
  [in, optional] PCUNICODE_STRING ReferenceString,
  [in]           WDFSTRING        String
);