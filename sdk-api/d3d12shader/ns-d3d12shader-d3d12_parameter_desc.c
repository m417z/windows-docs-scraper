typedef struct _D3D12_PARAMETER_DESC {
  LPCSTR                    Name;
  LPCSTR                    SemanticName;
  D3D_SHADER_VARIABLE_TYPE  Type;
  D3D_SHADER_VARIABLE_CLASS Class;
  UINT                      Rows;
  UINT                      Columns;
  D3D_INTERPOLATION_MODE    InterpolationMode;
  D3D_PARAMETER_FLAGS       Flags;
  UINT                      FirstInRegister;
  UINT                      FirstInComponent;
  UINT                      FirstOutRegister;
  UINT                      FirstOutComponent;
} D3D12_PARAMETER_DESC;