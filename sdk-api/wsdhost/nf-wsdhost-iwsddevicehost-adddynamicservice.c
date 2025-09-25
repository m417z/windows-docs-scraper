HRESULT AddDynamicService(
  [in]           LPCWSTR              pszServiceId,
  [in, optional] LPCWSTR              pszEndpointAddress,
  [in, optional] const WSD_PORT_TYPE  *pPortType,
  [in, optional] const WSDXML_NAME    *pPortName,
  [in, optional] const WSDXML_ELEMENT *pAny,
  [in, optional] IUnknown             *pService
);