HRESULT Init(
  [in]           LPCWSTR         pszDeviceId,
  [in]           IWSDAddress     *pDeviceAddress,
  [in]           LPCWSTR         pszLocalId,
  [in, optional] IWSDXMLContext  *pContext,
  [in, optional] IWSDDeviceProxy *pSponsor
);