HRESULT SLGetServerStatus(
  [in]           PCWSTR  pwszServerURL,
  [in]           PCWSTR  pwszAcquisitionType,
  [in, optional] PCWSTR  pwszProxyServer,
  [in, optional] WORD    wProxyPort,
  [out]          HRESULT *phrStatus
);