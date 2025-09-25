typedef struct WLAN_STATISTICS {
  ULONGLONG                 ullFourWayHandshakeFailures;
  ULONGLONG                 ullTKIPCounterMeasuresInvoked;
  ULONGLONG                 ullReserved;
  WLAN_MAC_FRAME_STATISTICS MacUcastCounters;
  WLAN_MAC_FRAME_STATISTICS MacMcastCounters;
  DWORD                     dwNumberOfPhys;
#if ...
  WLAN_PHY_FRAME_STATISTICS *PhyCounters[];
#else
  WLAN_PHY_FRAME_STATISTICS PhyCounters[1];
#endif
} WLAN_STATISTICS, *PWLAN_STATISTICS;