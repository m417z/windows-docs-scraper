typedef struct _DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO2 {
  DWORD                         LayerIndex;
  ULONGLONG                     PresentId;
  DXGKCB_NOTIFY_MPO_VSYNC_FLAGS Flags;
} DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO2;