typedef struct FWPS_CALLOUT2_ {
  GUID                                calloutKey;
  UINT32                              flags;
  FWPS_CALLOUT_CLASSIFY_FN2           classifyFn;
  FWPS_CALLOUT_NOTIFY_FN2             notifyFn;
  FWPS_CALLOUT_FLOW_DELETE_NOTIFY_FN0 flowDeleteFn;
} FWPS_CALLOUT2;