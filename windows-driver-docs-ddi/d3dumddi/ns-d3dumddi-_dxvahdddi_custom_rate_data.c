typedef struct _DXVAHDDDI_CUSTOM_RATE_DATA {
       DXVAHDDDI_RATIONAL CustomRate;
  [in] UINT               OutputFrames;
  [in] BOOL               InputInterlaced;
  [in] UINT               InputFramesOrFields;
} DXVAHDDDI_CUSTOM_RATE_DATA;