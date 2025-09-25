HRESULT WSDCreateDeviceProxy2(
  [in]  LPCWSTR          pszDeviceId,
  [in]  LPCWSTR          pszLocalId,
  [in]  IWSDXMLContext   *pContext,
  [in]  WSD_CONFIG_PARAM *pConfigParams,
  [in]  DWORD            dwConfigParamCount,
  [out] IWSDDeviceProxy  **ppDeviceProxy
);