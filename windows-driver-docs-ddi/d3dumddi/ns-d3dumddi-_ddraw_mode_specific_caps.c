typedef struct _DDRAW_MODE_SPECIFIC_CAPS {
  [in]  UINT Head;
  [out] UINT Caps;
  [out] UINT CKeyCaps;
  [out] UINT FxCaps;
  [out] UINT MaxVisibleOverlays;
  [out] UINT MinOverlayStretch;
  [out] UINT MaxOverlayStretch;
} DDRAW_MODE_SPECIFIC_CAPS;