VOID WdfDeviceSetDeviceInterfaceStateEx(
  WDFDEVICE        Device,
  const GUID       *InterfaceClassGUID,
  PCUNICODE_STRING ReferenceString,
  BOOLEAN          IsInterfaceEnabled
);