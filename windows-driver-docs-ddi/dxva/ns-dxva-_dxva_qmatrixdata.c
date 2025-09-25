typedef struct _DXVA_QmatrixData {
  BYTE bNewQmatrix[4];
  WORD *Qmatrix[4][DXVA_USUAL_BLOCK_WIDTH  DXVA_USUAL_BLOCK_HEIGHT];
} DXVA_QmatrixData, *LPDXVA_QmatrixData;