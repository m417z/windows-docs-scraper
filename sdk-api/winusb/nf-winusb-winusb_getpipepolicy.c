BOOL WinUsb_GetPipePolicy(
  [in]      WINUSB_INTERFACE_HANDLE InterfaceHandle,
  [in]      UCHAR                   PipeID,
  [in]      ULONG                   PolicyType,
  [in, out] PULONG                  ValueLength,
  [out]     PVOID                   Value
);