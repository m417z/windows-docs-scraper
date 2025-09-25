typedef struct FWPM_ACTION0_ {
  FWP_ACTION_TYPE type;
  union {
    GUID filterType;
    GUID calloutKey;
  };
} FWPM_ACTION0;