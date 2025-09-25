typedef struct _DWM_THUMBNAIL_PROPERTIES {
  DWORD dwFlags;
  RECT  rcDestination;
  RECT  rcSource;
  BYTE  opacity;
  BOOL  fVisible;
  BOOL  fSourceClientAreaOnly;
} DWM_THUMBNAIL_PROPERTIES, *PDWM_THUMBNAIL_PROPERTIES;