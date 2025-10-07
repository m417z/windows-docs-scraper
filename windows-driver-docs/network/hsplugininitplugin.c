DWORD HSPluginInitPlugin(
  _In_  HANDLE                hPluginContext,
  _In_  DWORD                 dwVerNumUsed,
  _In_  DWORD                 dwHostCapabilities,
  _In_  HS_DEVICE_IDENTITY    *pDeviceIdentity,
  _In_  HOTSPOT_HOST_HANDLERS *pHotspotHostHandlers,
  _Out_ HOTSPOT_PLUGIN_APIS   *pHotspotPluginAPIs,
  _Out_ HS_PLUGIN_PROFILE     *pPluginProfile
);