BOOL CryptMsgGetParam(
  [in]      HCRYPTMSG hCryptMsg,
  [in]      DWORD     dwParamType,
  [in]      DWORD     dwIndex,
  [out]     void      *pvData,
  [in, out] DWORD     *pcbData
);