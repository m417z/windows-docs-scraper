BOOL WinUsb_WriteIsochPipe(
  [in]           WINUSB_ISOCH_BUFFER_HANDLE BufferHandle,
  [in]           ULONG                      Offset,
  [in]           ULONG                      Length,
  [in, out]      PULONG                     FrameNumber,
  [in, optional] LPOVERLAPPED               Overlapped
);