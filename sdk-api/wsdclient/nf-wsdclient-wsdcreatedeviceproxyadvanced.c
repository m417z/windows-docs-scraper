HRESULT WSDCreateDeviceProxyAdvanced(
  [in]  LPCWSTR         pszDeviceId,
        IWSDAddress     *pDeviceAddress,
  [in]  LPCWSTR         pszLocalId,
  [in]  IWSDXMLContext  *pContext,
  [out] IWSDDeviceProxy **ppDeviceProxy
);