typedef struct _D3DDDI_PRESENT_MULTIPLANE_OVERLAY {
  UINT                                 LayerIndex;
  BOOL                                 Enabled;
  HANDLE                               hResource;
  UINT                                 SubResourceIndex;
  D3DDDI_MULTIPLANE_OVERLAY_ATTRIBUTES PlaneAttributes;
} D3DDDI_PRESENT_MULTIPLANE_OVERLAY;