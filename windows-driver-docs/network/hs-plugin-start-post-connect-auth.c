typedef DWORD (WINAPI *HS_PLUGIN_START_POST_CONNECT_AUTH)(
  _In_ DWORD                 dwConnectionId,
  _In_ HS_CONNECTION_CONTEXT *pConnectContext,
  _In_ HS_SIM_DATA           *pSIMData,
  _In_ HS_NETWORK_IDENTITY   *pNetworkIdentity,
  _In_ HS_NETWORK_PROFILE    *pNetworkProfile
);