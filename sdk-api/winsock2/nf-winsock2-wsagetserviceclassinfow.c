INT WSAAPI WSAGetServiceClassInfoW(
  [in]      LPGUID                 lpProviderId,
  [in]      LPGUID                 lpServiceClassId,
  [in, out] LPDWORD                lpdwBufSize,
  [out]     LPWSASERVICECLASSINFOW lpServiceClassInfo
);