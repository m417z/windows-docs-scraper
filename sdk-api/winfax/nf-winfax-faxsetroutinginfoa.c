WINFAXAPI BOOL FaxSetRoutingInfoA(
  [in] HANDLE     FaxPortHandle,
  [in] LPCSTR     RoutingGuid,
  [in] const BYTE *RoutingInfoBuffer,
  [in] DWORD      RoutingInfoBufferSize
);