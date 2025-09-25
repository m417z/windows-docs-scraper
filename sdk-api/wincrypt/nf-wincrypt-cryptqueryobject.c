BOOL CryptQueryObject(
  [in]  DWORD      dwObjectType,
  [in]  const void *pvObject,
  [in]  DWORD      dwExpectedContentTypeFlags,
  [in]  DWORD      dwExpectedFormatTypeFlags,
  [in]  DWORD      dwFlags,
  [out] DWORD      *pdwMsgAndCertEncodingType,
  [out] DWORD      *pdwContentType,
  [out] DWORD      *pdwFormatType,
  [out] HCERTSTORE *phCertStore,
  [out] HCRYPTMSG  *phMsg,
  [out] const void **ppvContext
);