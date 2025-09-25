BOOL WinUsb_GetPowerPolicy(
  [in]      WINUSB_INTERFACE_HANDLE InterfaceHandle,
  [in]      ULONG                   PolicyType,
  [in, out] PULONG                  ValueLength,
  [out]     PVOID                   Value
);