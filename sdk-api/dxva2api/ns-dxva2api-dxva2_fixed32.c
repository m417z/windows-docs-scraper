typedef struct _DXVA2_Fixed32 {
  union {
    struct {
      USHORT Fraction;
      SHORT  Value;
    };
    LONG ll;
  };
} DXVA2_Fixed32;