DWORD MprAdminMIBSetTrapInfo(
  [in]      DWORD   dwProtocolId,
  [in]      DWORD   dwRoutingPid,
  [in]      HANDLE  hEvent,
  [in]      LPVOID  lpInData,
  [in]      DWORD   dwInDataSize,
  [out]     LPVOID  *lplpOutData,
  [in, out] LPDWORD lpOutDataSize
);