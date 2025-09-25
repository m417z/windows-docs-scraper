typedef struct _DXVAHDDDI_CONTENT_DESC {
  [in] DXVAHDDDI_FRAME_FORMAT InputFrameFormat;
       DXVAHDDDI_RATIONAL     InputFrameRate;
  [in] UINT                   InputWidth;
  [in] UINT                   InputHeight;
       DXVAHDDDI_RATIONAL     OutputFrameRate;
  [in] UINT                   OutputWidth;
  [in] UINT                   OutputHeight;
} DXVAHDDDI_CONTENT_DESC;