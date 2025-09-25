typedef struct _WLAN_INTERFACE_CAPABILITY {
  WLAN_INTERFACE_TYPE interfaceType;
  BOOL                bDot11DSupported;
  DWORD               dwMaxDesiredSsidListSize;
  DWORD               dwMaxDesiredBssidListSize;
  DWORD               dwNumberOfSupportedPhys;
  DOT11_PHY_TYPE      dot11PhyTypes[WLAN_MAX_PHY_INDEX];
} WLAN_INTERFACE_CAPABILITY, *PWLAN_INTERFACE_CAPABILITY;