DOT11EXTIHV_CREATE_DISCOVERY_PROFILES Dot11extihvCreateDiscoveryProfiles;

DWORD Dot11extihvCreateDiscoveryProfiles(
  [in, optional] HANDLE hIhvExtAdapter,
  [in]           BOOL bInsecure,
  [in, optional] PDOT11EXT_IHV_PROFILE_PARAMS pIhvProfileParams,
  [in, optional] PDOT11_BSS_LIST pConnectableBssid,
  [out]          PDOT11EXT_IHV_DISCOVERY_PROFILE_LIST pIhvDiscoveryProfileList,
  [out]          PDWORD pdwReasonCode
)
{...}