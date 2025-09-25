HRESULT WSDGenerateFault(
  [in]  LPCWSTR        pszCode,
  [in]  LPCWSTR        pszSubCode,
  [in]  LPCWSTR        pszReason,
  [in]  LPCWSTR        pszDetail,
  [in]  IWSDXMLContext *pContext,
  [out] WSD_SOAP_FAULT **ppFault
);