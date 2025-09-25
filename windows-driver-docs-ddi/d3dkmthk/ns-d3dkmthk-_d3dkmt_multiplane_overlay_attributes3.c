typedef struct _D3DKMT_MULTIPLANE_OVERLAY_ATTRIBUTES3 {
  UINT                                      Flags;
  RECT                                      SrcRect;
  RECT                                      DstRect;
  RECT                                      ClipRect;
  D3DDDI_ROTATION                           Rotation;
  D3DKMT_MULTIPLANE_OVERLAY_BLEND           Blend;
  UINT                                      DirtyRectCount;
  RECT                                      *pDirtyRects;
  D3DDDI_COLOR_SPACE_TYPE                   ColorSpace;
  DXGKMT_MULTIPLANE_OVERLAY_STRETCH_QUALITY StretchQuality;
  UINT                                      SDRWhiteLevel;
} D3DKMT_MULTIPLANE_OVERLAY_ATTRIBUTES3;