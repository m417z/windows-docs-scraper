typedef struct _D3D10_SHADER_DEBUG_INPUT_INFO {
  UINT                       Var;
  D3D10_SHADER_DEBUG_REGTYPE InitialRegisterSet;
  UINT                       InitialBank;
  UINT                       InitialRegister;
  UINT                       InitialComponent;
  UINT                       InitialValue;
} D3D10_SHADER_DEBUG_INPUT_INFO;