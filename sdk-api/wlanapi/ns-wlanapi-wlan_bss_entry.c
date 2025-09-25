typedef struct _WLAN_BSS_ENTRY {
  DOT11_SSID        dot11Ssid;
  ULONG             uPhyId;
  DOT11_MAC_ADDRESS dot11Bssid;
  DOT11_BSS_TYPE    dot11BssType;
  DOT11_PHY_TYPE    dot11BssPhyType;
  LONG              lRssi;
  ULONG             uLinkQuality;
  BOOLEAN           bInRegDomain;
  USHORT            usBeaconPeriod;
  ULONGLONG         ullTimestamp;
  ULONGLONG         ullHostTimestamp;
  USHORT            usCapabilityInformation;
  ULONG             ulChCenterFrequency;
  WLAN_RATE_SET     wlanRateSet;
  ULONG             ulIeOffset;
  ULONG             ulIeSize;
} WLAN_BSS_ENTRY, *PWLAN_BSS_ENTRY;