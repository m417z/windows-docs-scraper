WINFAXAPI BOOL FaxSetRoutingInfoW(
  [in] HANDLE     FaxPortHandle,
  [in] LPCWSTR    RoutingGuid,
  [in] const BYTE *RoutingInfoBuffer,
  [in] DWORD      RoutingInfoBufferSize
);