typedef struct FWPS_CALLOUT1_ {
  GUID                                calloutKey;
  UINT32                              flags;
  FWPS_CALLOUT_CLASSIFY_FN1           classifyFn;
  FWPS_CALLOUT_NOTIFY_FN1             notifyFn;
  FWPS_CALLOUT_FLOW_DELETE_NOTIFY_FN0 flowDeleteFn;
} FWPS_CALLOUT1;