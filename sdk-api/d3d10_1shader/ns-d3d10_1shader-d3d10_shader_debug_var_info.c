typedef struct _D3D10_SHADER_DEBUG_VAR_INFO {
  UINT                       TokenId;
  D3D10_SHADER_VARIABLE_TYPE Type;
  UINT                       Register;
  UINT                       Component;
  UINT                       ScopeVar;
  UINT                       ScopeVarOffset;
} D3D10_SHADER_DEBUG_VAR_INFO;