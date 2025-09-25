DWORD WcmQueryProperty(
  [in, optional] const GUID   *pInterface,
  [in, optional] LPCWSTR      strProfileName,
  [in]           WCM_PROPERTY Property,
                 void         *pReserved,
  [out]          PDWORD       pdwDataSize,
  [out]          PBYTE        *ppData
);