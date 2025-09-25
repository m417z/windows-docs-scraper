typedef struct _DXGK_GAMMA_MATRIX_CAP {
  union {
    struct {
      UINT MatrixSizeX : 10;
      UINT MatrixSizeY : 10;
    };
    UINT Value;
  };
  DKGK_GAMMA_DATA_CAP GammaDataCap;
} DXGK_GAMMA_MATRIX_CAP, *PDXGK_GAMMA_MATRIX_CAP;