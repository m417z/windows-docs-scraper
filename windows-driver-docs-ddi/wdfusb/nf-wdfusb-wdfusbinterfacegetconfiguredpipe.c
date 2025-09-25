WDFUSBPIPE WdfUsbInterfaceGetConfiguredPipe(
  [in]                WDFUSBINTERFACE           UsbInterface,
  [in]                UCHAR                     PipeIndex,
  [in, out, optional] PWDF_USB_PIPE_INFORMATION PipeInfo
);