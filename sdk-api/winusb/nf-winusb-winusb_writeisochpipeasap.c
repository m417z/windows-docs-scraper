BOOL WinUsb_WriteIsochPipeAsap(
  [in]           WINUSB_ISOCH_BUFFER_HANDLE BufferHandle,
  [in]           ULONG                      Offset,
  [in]           ULONG                      Length,
  [in]           BOOL                       ContinueStream,
  [in, optional] LPOVERLAPPED               Overlapped
);