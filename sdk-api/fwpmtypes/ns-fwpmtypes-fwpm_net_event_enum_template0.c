typedef struct FWPM_NET_EVENT_ENUM_TEMPLATE0_ {
  FILETIME               startTime;
  FILETIME               endTime;
  UINT32                 numFilterConditions;
  FWPM_FILTER_CONDITION0 *filterCondition;
} FWPM_NET_EVENT_ENUM_TEMPLATE0;