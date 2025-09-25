typedef struct _DXGK_COLORTRANSFORMCAPS {
  union {
    struct {
      UINT Gamma_Rgb256x3x16 : 1;
      UINT Gamma_Dxgi1 : 1;
      UINT Transform_3x4Matrix : 1;
      UINT Transform_3x4Matrix_WideColor : 1;
      UINT Transform_3x4Matrix_HighColor : 1;
      UINT Transform_Matrix_V2 : 1;
#if ...
      UINT Reserved : 26;
#elif
      UINT Reserved : 27;
#else
      UINT Reserved : 30;
#endif
    };
    UINT Value;
  };
} DXGK_COLORTRANSFORMCAPS;