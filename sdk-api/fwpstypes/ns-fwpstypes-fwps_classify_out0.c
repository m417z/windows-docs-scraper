typedef struct FWPS_CLASSIFY_OUT0_ {
  FWP_ACTION_TYPE actionType;
  UINT64          outContext;
  UINT64          filterId;
  UINT32          rights;
  UINT32          flags;
  UINT32          reserved;
} FWPS_CLASSIFY_OUT0;