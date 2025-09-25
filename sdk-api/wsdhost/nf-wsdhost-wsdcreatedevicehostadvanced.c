HRESULT WSDCreateDeviceHostAdvanced(
  [in]  LPCWSTR        pszLocalId,
  [in]  IWSDXMLContext *pContext,
  [in]  IWSDAddress    **ppHostAddresses,
  [in]  DWORD          dwHostAddressCount,
  [out] IWSDDeviceHost **ppDeviceHost
);