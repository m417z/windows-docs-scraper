typedef struct _D3D12_SHADER_TYPE_DESC {
  D3D_SHADER_VARIABLE_CLASS Class;
  D3D_SHADER_VARIABLE_TYPE  Type;
  UINT                      Rows;
  UINT                      Columns;
  UINT                      Elements;
  UINT                      Members;
  UINT                      Offset;
  LPCSTR                    Name;
} D3D12_SHADER_TYPE_DESC;