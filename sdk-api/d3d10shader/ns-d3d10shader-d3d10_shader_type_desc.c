typedef struct _D3D10_SHADER_TYPE_DESC {
  D3D10_SHADER_VARIABLE_CLASS Class;
  D3D10_SHADER_VARIABLE_TYPE  Type;
  UINT                        Rows;
  UINT                        Columns;
  UINT                        Elements;
  UINT                        Members;
  UINT                        Offset;
} D3D10_SHADER_TYPE_DESC;