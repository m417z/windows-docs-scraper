typedef struct _DXGK_DIAGNOSTIC_PSR {
  DXGK_DIAGNOSTIC_HEADER Header;
  union {
    DXGK_DIAGNOSTIC_PSR_REFRESH_REASON RefreshReason;
    UINT                               Value;
  };
} DXGK_DIAGNOSTIC_PSR;