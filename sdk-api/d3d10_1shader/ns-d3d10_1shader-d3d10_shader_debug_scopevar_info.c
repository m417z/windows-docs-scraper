typedef struct _D3D10_SHADER_DEBUG_SCOPEVAR_INFO {
  UINT                        TokenId;
  D3D10_SHADER_DEBUG_VARTYPE  VarType;
  D3D10_SHADER_VARIABLE_CLASS Class;
  UINT                        Rows;
  UINT                        Columns;
  UINT                        StructMemberScope;
  UINT                        uArrayIndices;
  UINT                        ArrayElements;
  UINT                        ArrayStrides;
  UINT                        uVariables;
  UINT                        uFirstVariable;
} D3D10_SHADER_DEBUG_SCOPEVAR_INFO;