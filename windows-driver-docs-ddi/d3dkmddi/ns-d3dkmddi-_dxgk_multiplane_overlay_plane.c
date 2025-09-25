typedef struct _DXGK_MULTIPLANE_OVERLAY_PLANE {
       UINT                               LayerIndex;
       BOOL                               Enabled;
  [in] UINT                               AllocationSegment;
  [in] PHYSICAL_ADDRESS                   AllocationAddress;
       HANDLE                             hAllocation;
       DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES PlaneAttributes;
} DXGK_MULTIPLANE_OVERLAY_PLANE;