typedef struct DOT11_STATISTICS {
  NDIS_OBJECT_HEADER         Header;
  ULONGLONG                  ullFourWayHandshakeFailures;
  ULONGLONG                  ullTKIPCounterMeasuresInvoked;
  ULONGLONG                  ullReserved;
  DOT11_MAC_FRAME_STATISTICS MacUcastCounters;
  DOT11_MAC_FRAME_STATISTICS MacMcastCounters;
  DOT11_PHY_FRAME_STATISTICS PhyCounters[1];
} DOT11_STATISTICS, *PDOT11_STATISTICS;