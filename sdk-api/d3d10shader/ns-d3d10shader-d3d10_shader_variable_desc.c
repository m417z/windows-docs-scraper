typedef struct _D3D10_SHADER_VARIABLE_DESC {
  LPCSTR Name;
  UINT   StartOffset;
  UINT   Size;
  UINT   uFlags;
  LPVOID DefaultValue;
} D3D10_SHADER_VARIABLE_DESC;