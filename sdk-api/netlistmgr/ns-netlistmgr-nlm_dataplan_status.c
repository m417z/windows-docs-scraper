typedef struct NLM_DATAPLAN_STATUS {
  GUID           InterfaceGuid;
  NLM_USAGE_DATA UsageData;
  DWORD          DataLimitInMegabytes;
  DWORD          InboundBandwidthInKbps;
  DWORD          OutboundBandwidthInKbps;
  FILETIME       NextBillingCycle;
  DWORD          MaxTransferSizeInMegabytes;
  DWORD          Reserved;
} NLM_DATAPLAN_STATUS;