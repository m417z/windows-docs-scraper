typedef struct _DXGK_SEGMENTBANKPREFERENCE {
  union {
    struct {
      UINT Bank0 : 7;
      UINT Direction0 : 1;
      UINT Bank1 : 7;
      UINT Direction1 : 1;
      UINT Bank2 : 7;
      UINT Direction2 : 1;
      UINT Bank3 : 7;
      UINT Direction3 : 1;
    };
    [out] UINT Value;
  };
} DXGK_SEGMENTBANKPREFERENCE;