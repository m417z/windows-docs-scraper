typedef struct _DXVAHD_CUSTOM_RATE_DATA {
  DXVAHD_RATIONAL CustomRate;
  UINT            OutputFrames;
  BOOL            InputInterlaced;
  UINT            InputFramesOrFields;
} DXVAHD_CUSTOM_RATE_DATA;