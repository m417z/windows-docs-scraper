BOOL WinUsb_QueryPipe(
  [in]  WINUSB_INTERFACE_HANDLE  InterfaceHandle,
  [in]  UCHAR                    AlternateInterfaceNumber,
  [in]  UCHAR                    PipeIndex,
  [out] PWINUSB_PIPE_INFORMATION PipeInformation
);