VOID WdfUsbInterfaceGetDescriptor(
  [in]  WDFUSBINTERFACE           UsbInterface,
  [in]  UCHAR                     SettingIndex,
  [out] PUSB_INTERFACE_DESCRIPTOR InterfaceDescriptor
);