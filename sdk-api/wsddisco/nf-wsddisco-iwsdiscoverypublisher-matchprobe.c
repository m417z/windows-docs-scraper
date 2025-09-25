HRESULT MatchProbe(
  [in]           const WSD_SOAP_MESSAGE *pProbeMessage,
  [in]           IWSDMessageParameters  *pMessageParameters,
  [in]           LPCWSTR                pszId,
  [in]           ULONGLONG              ullMetadataVersion,
  [in]           ULONGLONG              ullInstanceId,
  [in]           ULONGLONG              ullMessageNumber,
  [in, optional] LPCWSTR                pszSessionId,
  [in, optional] const WSD_NAME_LIST    *pTypesList,
  [in, optional] const WSD_URI_LIST     *pScopesList,
  [in, optional] const WSD_URI_LIST     *pXAddrsList
);