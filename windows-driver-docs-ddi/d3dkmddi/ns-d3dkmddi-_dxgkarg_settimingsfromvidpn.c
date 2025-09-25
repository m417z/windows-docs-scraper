typedef struct _DXGKARG_SETTIMINGSFROMVIDPN {
  D3DKMDT_HVIDPN            hFunctionalVidPn;
  DXGK_SET_TIMING_FLAGS     SetFlags;
  PDXGK_SET_TIMING_RESULTS  pResultsFlags;
  UINT                      PathCount;
  DXGK_SET_TIMING_PATH_INFO *pSetTimingPathInfo;
} DXGKARG_SETTIMINGSFROMVIDPN;