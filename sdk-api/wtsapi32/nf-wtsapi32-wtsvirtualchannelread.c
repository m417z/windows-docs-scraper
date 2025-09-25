BOOL WTSVirtualChannelRead(
  [in]  HANDLE hChannelHandle,
  [in]  ULONG  TimeOut,
  [out] PCHAR  Buffer,
  [in]  ULONG  BufferSize,
  [out] PULONG pBytesRead
);