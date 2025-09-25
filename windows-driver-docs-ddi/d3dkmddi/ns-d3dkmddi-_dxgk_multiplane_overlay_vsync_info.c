typedef struct _DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO {
       DWORD                              LayerIndex;
       BOOL                               Enabled;
  [in] PHYSICAL_ADDRESS                   PhysicalAddress;
       DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES PlaneAttributes;
} DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO;