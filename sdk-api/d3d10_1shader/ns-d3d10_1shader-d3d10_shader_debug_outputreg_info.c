typedef struct _D3D10_SHADER_DEBUG_OUTPUTREG_INFO {
  D3D10_SHADER_DEBUG_REGTYPE   OutputRegisterSet;
  UINT                         OutputReg;
  UINT                         TempArrayReg;
  UINT                         OutputComponents[4];
  D3D10_SHADER_DEBUG_OUTPUTVAR OutputVars[4];
  UINT                         IndexReg;
  UINT                         IndexComp;
} D3D10_SHADER_DEBUG_OUTPUTREG_INFO;