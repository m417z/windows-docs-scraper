typedef struct _D3D10_SHADER_DEBUG_INST_INFO {
  UINT                              Id;
  UINT                              Opcode;
  UINT                              uOutputs;
  D3D10_SHADER_DEBUG_OUTPUTREG_INFO pOutputs[2];
  UINT                              TokenId;
  UINT                              NestingLevel;
  UINT                              Scopes;
  UINT                              ScopeInfo;
  UINT                              AccessedVars;
  UINT                              AccessedVarsInfo;
} D3D10_SHADER_DEBUG_INST_INFO;