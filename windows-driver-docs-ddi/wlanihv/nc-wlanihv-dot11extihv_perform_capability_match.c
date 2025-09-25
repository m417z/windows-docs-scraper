DOT11EXTIHV_PERFORM_CAPABILITY_MATCH Dot11extihvPerformCapabilityMatch;

DWORD Dot11extihvPerformCapabilityMatch(
  [in, optional] HANDLE hIhvExtAdapter,
  [in, optional] PDOT11EXT_IHV_PROFILE_PARAMS pIhvProfileParams,
  [in]           PDOT11EXT_IHV_CONNECTIVITY_PROFILE pIhvConnProfile,
  [in]           PDOT11EXT_IHV_SECURITY_PROFILE pIhvSecProfile,
  [in, optional] PDOT11_BSS_LIST pConnectableBssid,
  [out]          PDWORD pdwReasonCode
)
{...}