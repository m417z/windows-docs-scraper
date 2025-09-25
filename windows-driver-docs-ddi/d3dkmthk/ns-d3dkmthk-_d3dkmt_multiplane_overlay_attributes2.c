typedef struct _D3DKMT_MULTIPLANE_OVERLAY_ATTRIBUTES2 {
  UINT                                         Flags;
  RECT                                         SrcRect;
  RECT                                         DstRect;
  RECT                                         ClipRect;
  D3DDDI_ROTATION                              Rotation;
  D3DKMT_MULTIPLANE_OVERLAY_BLEND              Blend;
  UINT                                         DirtyRectCount;
  RECT                                         *pDirtyRects;
  D3DKMT_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT VideoFrameFormat;
  D3DDDI_COLOR_SPACE_TYPE                      ColorSpace;
  D3DKMT_MULTIPLANE_OVERLAY_STEREO_FORMAT      StereoFormat;
  BOOL                                         StereoLeftViewFrame0;
  BOOL                                         StereoBaseViewFrame0;
  DXGKMT_MULTIPLANE_OVERLAY_STEREO_FLIP_MODE   StereoFlipMode;
  DXGKMT_MULTIPLANE_OVERLAY_STRETCH_QUALITY    StretchQuality;
  UINT                                         Reserved1;
} D3DKMT_MULTIPLANE_OVERLAY_ATTRIBUTES2;