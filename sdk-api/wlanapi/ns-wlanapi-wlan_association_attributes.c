typedef struct _WLAN_ASSOCIATION_ATTRIBUTES {
  DOT11_SSID          dot11Ssid;
  DOT11_BSS_TYPE      dot11BssType;
  DOT11_MAC_ADDRESS   dot11Bssid;
  DOT11_PHY_TYPE      dot11PhyType;
  ULONG               uDot11PhyIndex;
  WLAN_SIGNAL_QUALITY wlanSignalQuality;
  ULONG               ulRxRate;
  ULONG               ulTxRate;
} WLAN_ASSOCIATION_ATTRIBUTES, *PWLAN_ASSOCIATION_ATTRIBUTES;