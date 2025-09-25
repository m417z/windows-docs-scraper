typedef struct FWPS_CALLOUT3_ {
  GUID                                calloutKey;
  UINT32                              flags;
  FWPS_CALLOUT_CLASSIFY_FN3           classifyFn;
  FWPS_CALLOUT_NOTIFY_FN3             notifyFn;
  FWPS_CALLOUT_FLOW_DELETE_NOTIFY_FN0 flowDeleteFn;
} FWPS_CALLOUT3;