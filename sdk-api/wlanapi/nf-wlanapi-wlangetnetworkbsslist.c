DWORD WlanGetNetworkBssList(
  [in]       HANDLE            hClientHandle,
  [in]       const GUID        *pInterfaceGuid,
  [optional] const PDOT11_SSID pDot11Ssid,
  [in]       DOT11_BSS_TYPE    dot11BssType,
  [in]       BOOL              bSecurityEnabled,
             PVOID             pReserved,
  [out]      PWLAN_BSS_LIST    *ppWlanBssList
);