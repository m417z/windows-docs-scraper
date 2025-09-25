typedef struct _D3DDDI_MULTIPLANE_OVERLAY_ATTRIBUTES {
  UINT                                         Flags;
  RECT                                         SrcRect;
  RECT                                         DstRect;
  RECT                                         ClipRect;
  D3DDDI_ROTATION                              Rotation;
  D3DDDI_MULTIPLANE_OVERLAY_BLEND              Blend;
  UINT                                         DirtyRectCount;
  RECT                                         *pDirtyRects;
  UINT                                         NumFilters;
  void                                         *pFilters;
  D3DDDI_MULTIPLANE_OVERLAY_VIDEO_FRAME_FORMAT VideoFrameFormat;
  UINT                                         YCbCrFlags;
  D3DDDI_MULTIPLANE_OVERLAY_STRETCH_QUALITY    StretchQuality;
} D3DDDI_MULTIPLANE_OVERLAY_ATTRIBUTES;