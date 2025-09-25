typedef struct _DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES3 {
  DXGK_MULTIPLANE_OVERLAY_FLAGS           Flags;
  RECT                                    SrcRect;
  RECT                                    DstRect;
  RECT                                    ClipRect;
  D3DDDI_ROTATION                         Rotation;
  DXGK_MULTIPLANE_OVERLAY_BLEND           Blend;
  D3DDDI_COLOR_SPACE_TYPE                 ColorSpaceType;
  DXGK_MULTIPLANE_OVERLAY_STRETCH_QUALITY StretchQuality;
  UINT                                    SDRWhiteLevel;
  UINT                                    DirtyRectCnt;
  const RECT                              *pDirtyRects;
} DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES3;