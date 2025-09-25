typedef struct _DXVADDI_FIXED32 {
  union {
    struct {
      USHORT Fraction;
      SHORT  Value;
    };
         LONG ll;
  };
} DXVADDI_FIXED32;