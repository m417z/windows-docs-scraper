typedef struct _D3D10_SHADER_DEBUG_SCOPE_INFO {
  D3D10_SHADER_DEBUG_SCOPETYPE ScopeType;
  UINT                         Name;
  UINT                         uNameLen;
  UINT                         uVariables;
  UINT                         VariableData;
} D3D10_SHADER_DEBUG_SCOPE_INFO;