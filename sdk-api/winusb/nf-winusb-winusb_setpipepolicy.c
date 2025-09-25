BOOL WinUsb_SetPipePolicy(
  [in] WINUSB_INTERFACE_HANDLE InterfaceHandle,
  [in] UCHAR                   PipeID,
  [in] ULONG                   PolicyType,
  [in] ULONG                   ValueLength,
  [in] PVOID                   Value
);