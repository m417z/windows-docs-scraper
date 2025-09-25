typedef struct _DXGK_DIAGNOSTIC_SYNCLOCK_ENABLESYNC {
  DXGK_DIAGNOSTIC_HEADER Header;
  union {
    struct {
      UINT DuringSetTiming : 1;
      UINT EnableSyncStart : 1;
      UINT EnableSyncEnd : 1;
      UINT Reserved : 29;
    } SyncLockEnableSync;
    UINT Value;
  };
} DXGK_DIAGNOSTIC_SYNCLOCK_ENABLESYNC;