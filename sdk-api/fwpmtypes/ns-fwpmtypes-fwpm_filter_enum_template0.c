typedef struct FWPM_FILTER_ENUM_TEMPLATE0_ {
  GUID                                 *providerKey;
  GUID                                 layerKey;
  FWP_FILTER_ENUM_TYPE                 enumType;
  UINT32                               flags;
  FWPM_PROVIDER_CONTEXT_ENUM_TEMPLATE0 *providerContextTemplate;
  UINT32                               numFilterConditions;
  FWPM_FILTER_CONDITION0               *filterCondition;
  UINT32                               actionMask;
  GUID                                 *calloutKey;
} FWPM_FILTER_ENUM_TEMPLATE0;