typedef struct _D3DKMT_SET_COLORSPACE_TRANSFORM {
  LUID                           AdapterLuid;
  D3DDDI_VIDEO_PRESENT_TARGET_ID VidPnTargetId;
  D3DDDI_GAMMARAMP_TYPE          Type;
  UINT                           Size;
  union {
    D3DKMDT_3x4_COLORSPACE_TRANSFORM *pColorSpaceTransform;
  };
} D3DKMT_SET_COLORSPACE_TRANSFORM;