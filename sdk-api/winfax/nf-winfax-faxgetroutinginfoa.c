WINFAXAPI BOOL FaxGetRoutingInfoA(
  [in]  HANDLE  FaxPortHandle,
  [in]  LPCSTR  RoutingGuid,
  [out] LPBYTE  *RoutingInfoBuffer,
  [out] LPDWORD RoutingInfoBufferSize
);