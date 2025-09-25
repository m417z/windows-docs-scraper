typedef struct _DXGK_INVALIDATEHWCONTEXTFLAGS {
  union {
    struct {
      UINT CollateralDamage : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} DXGK_INVALIDATEHWCONTEXTFLAGS;