typedef struct _DXGK_POINTERFLAGS {
  union {
    struct {
      UINT Monochrome : 1;
      UINT Color : 1;
      UINT MaskedColor : 1;
      UINT Reserved : 29;
    };
    UINT Value;
  };
} DXGK_POINTERFLAGS;