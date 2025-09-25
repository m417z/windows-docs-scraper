typedef struct D3DDDI_MAKERESIDENT_FLAGS {
  union {
    struct {
      UINT CantTrimFurther : 1;
      UINT MustSucceed : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} D3DDDI_MAKERESIDENT_FLAGS;