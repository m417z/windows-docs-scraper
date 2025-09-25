typedef struct _D3D10_SHADER_DEBUG_OUTPUTVAR {
  UINT  Var;
  UINT  uValueMin;
  UINT  uValueMax;
  INT   iValueMin;
  INT   iValueMax;
  FLOAT fValueMin;
  FLOAT fValueMax;
  BOOL  bNaNPossible;
  BOOL  bInfPossible;
} D3D10_SHADER_DEBUG_OUTPUTVAR;