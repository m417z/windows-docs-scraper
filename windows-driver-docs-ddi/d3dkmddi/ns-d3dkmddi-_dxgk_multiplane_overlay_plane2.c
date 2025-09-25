typedef struct _DXGK_MULTIPLANE_OVERLAY_PLANE2 {
  UINT                                LayerIndex;
  BOOL                                Enabled;
  UINT                                AllocationSegment;
  PHYSICAL_ADDRESS                    AllocationAddress;
  HANDLE                              hAllocation;
  DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES2 PlaneAttributes;
} DXGK_MULTIPLANE_OVERLAY_PLANE2;