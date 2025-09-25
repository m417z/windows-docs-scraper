BOOL WinUsb_QueryInterfaceSettings(
  [in]  WINUSB_INTERFACE_HANDLE   InterfaceHandle,
  [in]  UCHAR                     AlternateInterfaceNumber,
  [out] PUSB_INTERFACE_DESCRIPTOR UsbAltInterfaceDescriptor
);