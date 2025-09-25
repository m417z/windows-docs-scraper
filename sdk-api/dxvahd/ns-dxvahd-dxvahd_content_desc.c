typedef struct _DXVAHD_CONTENT_DESC {
  DXVAHD_FRAME_FORMAT InputFrameFormat;
  DXVAHD_RATIONAL     InputFrameRate;
  UINT                InputWidth;
  UINT                InputHeight;
  DXVAHD_RATIONAL     OutputFrameRate;
  UINT                OutputWidth;
  UINT                OutputHeight;
} DXVAHD_CONTENT_DESC;