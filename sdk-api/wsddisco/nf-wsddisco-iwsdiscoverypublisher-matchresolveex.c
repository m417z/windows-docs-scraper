HRESULT MatchResolveEx(
  [in]           const WSD_SOAP_MESSAGE *pResolveMessage,
  [in]           IWSDMessageParameters  *pMessageParameters,
  [in]           LPCWSTR                pszId,
  [in]           ULONGLONG              ullMetadataVersion,
  [in]           ULONGLONG              ullInstanceId,
  [in]           ULONGLONG              ullMessageNumber,
  [in, optional] LPCWSTR                pszSessionId,
  [in, optional] const WSD_NAME_LIST    *pTypesList,
  [in, optional] const WSD_URI_LIST     *pScopesList,
  [in, optional] const WSD_URI_LIST     *pXAddrsList,
  [in, optional] const WSDXML_ELEMENT   *pHeaderAny,
  [in, optional] const WSDXML_ELEMENT   *pReferenceParameterAny,
  [in, optional] const WSDXML_ELEMENT   *pPolicyAny,
  [in, optional] const WSDXML_ELEMENT   *pEndpointReferenceAny,
  [in, optional] const WSDXML_ELEMENT   *pAny
);