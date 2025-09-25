BOOL WTSVirtualChannelQuery(
  [in]  HANDLE            hChannelHandle,
        WTS_VIRTUAL_CLASS unnamedParam2,
  [out] PVOID             *ppBuffer,
  [out] DWORD             *pBytesReturned
);