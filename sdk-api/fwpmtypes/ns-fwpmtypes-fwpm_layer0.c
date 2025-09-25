typedef struct FWPM_LAYER0_ {
  GUID               layerKey;
  FWPM_DISPLAY_DATA0 displayData;
  UINT32             flags;
  UINT32             numFields;
  FWPM_FIELD0        *field;
  GUID               defaultSubLayerKey;
  UINT16             layerId;
} FWPM_LAYER0;