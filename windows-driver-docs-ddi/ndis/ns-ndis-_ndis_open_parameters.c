typedef struct _NDIS_OPEN_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  PNDIS_STRING       AdapterName;
  PNDIS_MEDIUM       MediumArray;
  UINT               MediumArraySize;
  PUINT              SelectedMediumIndex;
  PNET_FRAME_TYPE    FrameTypeArray;
  UINT               FrameTypeArraySize;
} NDIS_OPEN_PARAMETERS, *PNDIS_OPEN_PARAMETERS;