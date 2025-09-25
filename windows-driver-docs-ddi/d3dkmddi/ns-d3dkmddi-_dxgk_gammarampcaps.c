typedef struct _DXGK_GAMMARAMPCAPS {
  union {
    struct {
      UINT Gamma_Rgb256x3x16 : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} DXGK_GAMMARAMPCAPS;