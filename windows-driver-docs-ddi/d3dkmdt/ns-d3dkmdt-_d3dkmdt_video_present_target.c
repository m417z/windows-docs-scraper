typedef struct _D3DKMDT_VIDEO_PRESENT_TARGET {
  D3DDDI_VIDEO_PRESENT_TARGET_ID        Id;
  D3DKMDT_VIDEO_OUTPUT_TECHNOLOGY       VideoOutputTechnology;
  DXGK_CHILD_DEVICE_HPD_AWARENESS       VideoOutputHpdAwareness;
  D3DKMDT_MONITOR_ORIENTATION_AWARENESS MonitorOrientationAwareness;
  BOOLEAN                               SupportsSdtvModes;
} D3DKMDT_VIDEO_PRESENT_TARGET;