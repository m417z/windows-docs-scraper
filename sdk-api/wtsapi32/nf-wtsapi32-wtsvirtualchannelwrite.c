BOOL WTSVirtualChannelWrite(
  [in]  HANDLE hChannelHandle,
  [in]  PCHAR  Buffer,
  [in]  ULONG  Length,
  [out] PULONG pBytesWritten
);