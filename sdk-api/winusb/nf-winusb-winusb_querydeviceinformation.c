BOOL WinUsb_QueryDeviceInformation(
  [in]      WINUSB_INTERFACE_HANDLE InterfaceHandle,
  [in]      ULONG                   InformationType,
  [in, out] PULONG                  BufferLength,
  [out]     PVOID                   Buffer
);