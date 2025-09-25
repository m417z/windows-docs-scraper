typedef struct _DXGK_DIAGTYPE_PROGRESSIONS {
  union {
    struct {
      UINT SyncLockEnableSync : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} DXGK_DIAGTYPE_PROGRESSIONS;