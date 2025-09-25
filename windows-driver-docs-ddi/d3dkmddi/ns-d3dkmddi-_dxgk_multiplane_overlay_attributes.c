typedef struct _DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES {
  DXGK_MULTIPLANE_OVERLAY_FLAGS              Flags;
  RECT                                       SrcRect;
  RECT                                       DstRect;
  RECT                                       ClipRect;
  D3DDDI_ROTATION                            Rotation;
  DXGK_MULTIPLANE_OVERLAY_BLEND              Blend;
  UINT                                       NumFilters;
  void                                       *pFilters;
  DXGK_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT VideoFrameFormat;
  DXGK_MULTIPLANE_OVERLAY_YCbCr_FLAGS        YCbCrFlags;
  DXGK_MULTIPLANE_OVERLAY_STEREO_FORMAT      StereoFormat;
  BOOL                                       StereoLeftViewFrame0;
  BOOL                                       StereoBaseViewFrame0;
  DXGK_MULTIPLANE_OVERLAY_STEREO_FLIP_MODE   StereoFlipMode;
  DXGK_MULTIPLANE_OVERLAY_STRETCH_QUALITY    StretchQuality;
} DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES;