BOOL WinUsb_ReadPipe(
  [in]            WINUSB_INTERFACE_HANDLE InterfaceHandle,
  [in]            UCHAR                   PipeID,
  [out]           PUCHAR                  Buffer,
  [in]            ULONG                   BufferLength,
  [out, optional] PULONG                  LengthTransferred,
  [in, optional]  LPOVERLAPPED            Overlapped
);