typedef struct _DXGK_FLIPCAPS {
  union {
    struct {
      UINT FlipOnVSyncWithNoWait : 1;
      UINT FlipOnVSyncMmIo : 1;
      UINT FlipInterval : 1;
      UINT FlipImmediateMmIo : 1;
      UINT FlipIndependent : 1;
      UINT DdiPresentForIFlip : 1;
      UINT FlipImmediateOnHSync : 1;
#if ...
      UINT Reserved : 25;
#elif
      UINT Reserved : 27;
#else
      UINT Reserved : 28;
#endif
    };
    UINT Value;
  };
} DXGK_FLIPCAPS;