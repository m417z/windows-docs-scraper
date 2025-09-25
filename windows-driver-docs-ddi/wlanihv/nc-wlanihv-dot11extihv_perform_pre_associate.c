DOT11EXTIHV_PERFORM_PRE_ASSOCIATE Dot11extihvPerformPreAssociate;

DWORD Dot11extihvPerformPreAssociate(
  [in, optional] HANDLE hIhvExtAdapter,
  [in, optional] HANDLE hConnectSession,
  [in, optional] PDOT11EXT_IHV_PROFILE_PARAMS pIhvProfileParams,
  [in]           PDOT11EXT_IHV_CONNECTIVITY_PROFILE pIhvConnProfile,
  [in]           PDOT11EXT_IHV_SECURITY_PROFILE pIhvSecProfile,
  [in]           PDOT11_BSS_LIST pConnectableBssid,
  [out]          PDWORD pdwReasonCode
)
{...}