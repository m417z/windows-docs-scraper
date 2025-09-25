DWORD WcmSetProperty(
  [in, optional] const GUID   *pInterface,
  [in, optional] LPCWSTR      strProfileName,
  [in]           WCM_PROPERTY Property,
                 void         *pReserved,
  [in]           DWORD        dwDataSize,
  [in, optional] const BYTE   *pbData
);