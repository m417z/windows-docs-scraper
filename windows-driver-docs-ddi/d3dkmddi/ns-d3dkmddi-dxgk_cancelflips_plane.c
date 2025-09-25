typedef struct _DXGK_CANCELFLIPS_PLANE {
  ULONGLONG PresentIdCancelRequested;
  ULONGLONG PresentIdCancelled;
  UINT      LayerIndex;
} DXGK_CANCELFLIPS_PLANE;