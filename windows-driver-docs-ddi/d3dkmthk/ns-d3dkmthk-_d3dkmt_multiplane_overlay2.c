typedef struct _D3DKMT_MULTIPLANE_OVERLAY2 {
  UINT                                  LayerIndex;
  BOOL                                  Enabled;
  D3DKMT_HANDLE                         hAllocation;
  D3DKMT_MULTIPLANE_OVERLAY_ATTRIBUTES2 PlaneAttributes;
} D3DKMT_MULTIPLANE_OVERLAY2;