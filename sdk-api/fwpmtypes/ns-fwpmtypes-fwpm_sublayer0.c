typedef struct FWPM_SUBLAYER0_ {
  GUID               subLayerKey;
  FWPM_DISPLAY_DATA0 displayData;
  UINT32             flags;
  GUID               *providerKey;
  FWP_BYTE_BLOB      providerData;
  UINT16             weight;
} FWPM_SUBLAYER0;