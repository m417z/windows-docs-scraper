BOOL WinUsb_WritePipe(
  [in]            WINUSB_INTERFACE_HANDLE InterfaceHandle,
  [in]            UCHAR                   PipeID,
  [in]            PUCHAR                  Buffer,
  [in]            ULONG                   BufferLength,
  [out, optional] PULONG                  LengthTransferred,
  [in, optional]  LPOVERLAPPED            Overlapped
);