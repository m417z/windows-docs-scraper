typedef struct FWPS_FILTER1_ {
  UINT64                 filterId;
  FWP_VALUE0             weight;
  UINT16                 subLayerWeight;
  UINT16                 flags;
  UINT32                 numFilterConditions;
  FWPS_FILTER_CONDITION0 *filterCondition;
  FWPS_ACTION0           action;
  UINT64                 context;
  FWPM_PROVIDER_CONTEXT1 *providerContext;
} FWPS_FILTER1;