VOID WdfUsbInterfaceGetEndpointInformation(
  [in]      WDFUSBINTERFACE           UsbInterface,
  [in]      UCHAR                     SettingIndex,
  [in]      UCHAR                     EndpointIndex,
  [in, out] PWDF_USB_PIPE_INFORMATION EndpointInfo
);