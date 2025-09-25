HRESULT WSDCreateDeviceHost2(
  [in]  LPCWSTR          pszLocalId,
  [in]  IWSDXMLContext   *pContext,
  [in]  WSD_CONFIG_PARAM *pConfigParams,
  [in]  DWORD            dwConfigParamCount,
  [out] IWSDDeviceHost   **ppDeviceHost
);