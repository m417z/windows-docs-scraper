typedef struct _DRM_CLIENT_VERSION_INFO {
  UINT  uStructVersion;
  DWORD dwVersion[4];
  WCHAR wszHierarchy[256];
  WCHAR wszProductId[256];
  WCHAR wszProductDescription[256];
  void  _DRM_CLIENT_VERSION_INFO();
} DRM_CLIENT_VERSION_INFO;