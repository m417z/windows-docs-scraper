typedef struct _DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES2 {
  DXGK_MULTIPLANE_OVERLAY_FLAGS              Flags;
  RECT                                       SrcRect;
  RECT                                       DstRect;
  RECT                                       ClipRect;
  D3DDDI_ROTATION                            Rotation;
  DXGK_MULTIPLANE_OVERLAY_BLEND              Blend;
  DXGK_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT VideoFrameFormat;
  D3DDDI_COLOR_SPACE_TYPE                    ColorSpaceType;
  DXGK_MULTIPLANE_OVERLAY_STEREO_FORMAT      StereoFormat;
  BOOL                                       StereoLeftViewFrame0;
  BOOL                                       StereoBaseViewFrame0;
  DXGK_MULTIPLANE_OVERLAY_STEREO_FLIP_MODE   StereoFlipMode;
  DXGK_MULTIPLANE_OVERLAY_STRETCH_QUALITY    StretchQuality;
  UINT                                       Reserved1;
} DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES2;