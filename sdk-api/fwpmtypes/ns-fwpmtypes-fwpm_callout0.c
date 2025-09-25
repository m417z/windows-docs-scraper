typedef struct FWPM_CALLOUT0_ {
  GUID               calloutKey;
  FWPM_DISPLAY_DATA0 displayData;
  UINT32             flags;
  GUID               *providerKey;
  FWP_BYTE_BLOB      providerData;
  GUID               applicableLayer;
  UINT32             calloutId;
} FWPM_CALLOUT0;