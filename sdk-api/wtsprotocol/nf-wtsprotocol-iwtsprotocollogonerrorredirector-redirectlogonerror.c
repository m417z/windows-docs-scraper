HRESULT RedirectLogonError(
  [in]  LONG                                ntsStatus,
  [in]  LONG                                ntsSubstatus,
  [in]  LPCWSTR                             pszCaption,
  [in]  LPCWSTR                             pszMessage,
  [in]  UINT                                uType,
  [out] WTS_LOGON_ERROR_REDIRECTOR_RESPONSE *pResponse
);