typedef struct _HS_PLUGIN_PROFILE {
  DWORD dwPluginCapabilities;
  DWORD dwNumNetworksSupported;
  DWORD dwProviderNameStringID;
  DWORD dwGenericNetworkNameStringID;
  DWORD dwAdvancedPageStringID;
  DWORD dwProfileUpdateTimeDays;
  WCHAR szRealm[HS_CONST_MAX_REALM_LENGTH+1];
  DWORD dwSupportedSIMCount;
} HS_PLUGIN_PROFILE, *PHS_PLUGIN_PROFILE;