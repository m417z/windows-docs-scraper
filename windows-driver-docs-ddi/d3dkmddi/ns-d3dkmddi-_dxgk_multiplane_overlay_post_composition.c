typedef struct _DXGK_MULTIPLANE_OVERLAY_POST_COMPOSITION {
  DXGK_MULTIPLANE_OVERLAY_POST_COMPOSITION_FLAGS Flags;
  RECT                                           SrcRect;
  RECT                                           DstRect;
  D3DDDI_ROTATION                                Rotation;
} DXGK_MULTIPLANE_OVERLAY_POST_COMPOSITION;