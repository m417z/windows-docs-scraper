INT WSAAPI WSAGetServiceClassInfoA(
  [in]      LPGUID                 lpProviderId,
  [in]      LPGUID                 lpServiceClassId,
  [in, out] LPDWORD                lpdwBufSize,
  [out]     LPWSASERVICECLASSINFOA lpServiceClassInfo
);