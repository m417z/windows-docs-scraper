DWORD MprAdminMIBGetTrapInfo(
  [in]      MIB_SERVER_HANDLE hMibServer,
  [in]      DWORD             dwProtocolId,
  [in]      DWORD             dwRoutingPid,
  [in]      LPVOID            lpInData,
  [in]      DWORD             dwInDataSize,
  [out]     LPVOID            *lplpOutData,
  [in, out] LPDWORD           lpOutDataSize
);