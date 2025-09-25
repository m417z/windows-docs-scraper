HRESULT AccessCheck(
  [in] WBEM_CWSTR wszQueryLanguage,
  [in] WBEM_CWSTR wszQuery,
  [in] long       lSidLength,
  [in] const BYTE *pSid
);