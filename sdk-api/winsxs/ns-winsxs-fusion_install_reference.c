typedef struct _FUSION_INSTALL_REFERENCE_ {
  DWORD   cbSize;
  DWORD   dwFlags;
  GUID    guidScheme;
  LPCWSTR szIdentifier;
  LPCWSTR szNonCannonicalData;
} FUSION_INSTALL_REFERENCE, *LPFUSION_INSTALL_REFERENCE;