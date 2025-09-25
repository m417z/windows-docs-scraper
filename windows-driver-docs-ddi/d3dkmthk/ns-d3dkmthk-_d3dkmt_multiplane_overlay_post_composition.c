typedef struct _D3DKMT_MULTIPLANE_OVERLAY_POST_COMPOSITION {
  D3DKMT_MULTIPLANE_OVERLAY_POST_COMPOSITION_FLAGS Flags;
  RECT                                             SrcRect;
  RECT                                             DstRect;
  D3DDDI_ROTATION                                  Rotation;
} D3DKMT_MULTIPLANE_OVERLAY_POST_COMPOSITION;