typedef struct _WLAN_REALTIME_CONNECTION_QUALITY {
  DOT11_PHY_TYPE                             dot11PhyType;
  ULONG                                      ulLinkQuality;
  ULONG                                      ulRxRate;
  ULONG                                      ulTxRate;
  BOOL                                       bIsMLOConnection;
  ULONG                                      ulNumLinks;
  WLAN_REALTIME_CONNECTION_QUALITY_LINK_INFO linksInfo[1];
} WLAN_REALTIME_CONNECTION_QUALITY, *PWLAN_REALTIME_CONNECTION_QUALITY;