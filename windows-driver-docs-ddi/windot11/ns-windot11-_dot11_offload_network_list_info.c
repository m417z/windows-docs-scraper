typedef struct _DOT11_OFFLOAD_NETWORK_LIST_INFO {
  NDIS_OBJECT_HEADER    Header;
  ULONG                 ulFlags;
  ULONG                 FastScanPeriod;
  ULONG                 FastScanIterations;
  ULONG                 SlowScanPeriod;
  ULONG                 uNumOfEntries;
  DOT11_OFFLOAD_NETWORK offloadNetworkList[1];
} DOT11_OFFLOAD_NETWORK_LIST_INFO, *PDOT11_OFFLOAD_NETWORK_LIST_INFO;