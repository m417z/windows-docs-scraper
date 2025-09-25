HRESULT WSDGenerateFaultEx(
  [in]  WSDXML_NAME               *pCode,
  [in]  WSDXML_NAME               *pSubCode,
  [in]  WSD_LOCALIZED_STRING_LIST *pReasons,
  [in]  LPCWSTR                   pszDetail,
  [out] WSD_SOAP_FAULT            **ppFault
);