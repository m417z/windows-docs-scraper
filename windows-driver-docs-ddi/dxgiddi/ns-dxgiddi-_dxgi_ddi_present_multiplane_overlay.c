typedef struct _DXGI_DDI_PRESENT_MULTIPLANE_OVERLAY {
  UINT                                   LayerIndex;
  BOOL                                   Enabled;
  DXGI_DDI_HRESOURCE                     hResource;
  UINT                                   SubResourceIndex;
  DXGI_DDI_MULTIPLANE_OVERLAY_ATTRIBUTES PlaneAttributes;
} DXGI_DDI_PRESENT_MULTIPLANE_OVERLAY;