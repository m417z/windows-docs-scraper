typedef struct _DXVAHD_VPDEVCAPS {
  DXVAHD_DEVICE_TYPE DeviceType;
  UINT               DeviceCaps;
  UINT               FeatureCaps;
  UINT               FilterCaps;
  UINT               InputFormatCaps;
  D3DPOOL            InputPool;
  UINT               OutputFormatCount;
  UINT               InputFormatCount;
  UINT               VideoProcessorCount;
  UINT               MaxInputStreams;
  UINT               MaxStreamStates;
} DXVAHD_VPDEVCAPS;