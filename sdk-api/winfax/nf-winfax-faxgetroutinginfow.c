WINFAXAPI BOOL FaxGetRoutingInfoW(
  [in]  HANDLE  FaxPortHandle,
  [in]  LPCWSTR RoutingGuid,
  [out] LPBYTE  *RoutingInfoBuffer,
  [out] LPDWORD RoutingInfoBufferSize
);