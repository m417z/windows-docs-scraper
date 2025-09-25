typedef struct _D3DDDI_COLORFILLFLAGS {
  union {
    struct {
      UINT PresentToDwm : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} D3DDDI_COLORFILLFLAGS;