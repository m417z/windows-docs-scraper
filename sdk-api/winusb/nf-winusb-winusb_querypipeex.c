BOOL WinUsb_QueryPipeEx(
  [in]  WINUSB_INTERFACE_HANDLE     InterfaceHandle,
  [in]  UCHAR                       AlternateSettingNumber,
  [in]  UCHAR                       PipeIndex,
  [out] PWINUSB_PIPE_INFORMATION_EX PipeInformationEx
);