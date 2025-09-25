typedef struct FWPM_FILTER0_ {
  GUID                   filterKey;
  FWPM_DISPLAY_DATA0     displayData;
  UINT32                 flags;
  GUID                   *providerKey;
  FWP_BYTE_BLOB          providerData;
  GUID                   layerKey;
  GUID                   subLayerKey;
  FWP_VALUE0             weight;
  UINT32                 numFilterConditions;
  FWPM_FILTER_CONDITION0 *filterCondition;
  FWPM_ACTION0           action;
  union {
    UINT64 rawContext;
    GUID   providerContextKey;
  };
  GUID                   *reserved;
  UINT64                 filterId;
  FWP_VALUE0             effectiveWeight;
} FWPM_FILTER0;