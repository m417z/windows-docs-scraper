typedef struct _WCM_DATAPLAN_STATUS {
  WCM_USAGE_DATA         UsageData;
  DWORD                  DataLimitInMegabytes;
  DWORD                  InboundBandwidthInKbps;
  DWORD                  OutboundBandwidthInKbps;
  WCM_BILLING_CYCLE_INFO BillingCycle;
  DWORD                  MaxTransferSizeInMegabytes;
  DWORD                  Reserved;
} WCM_DATAPLAN_STATUS, *PWCM_DATAPLAN_STATUS;