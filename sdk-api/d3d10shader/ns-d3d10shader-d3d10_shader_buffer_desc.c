typedef struct _D3D10_SHADER_BUFFER_DESC {
  LPCSTR             Name;
  D3D10_CBUFFER_TYPE Type;
  UINT               Variables;
  UINT               Size;
  UINT               uFlags;
} D3D10_SHADER_BUFFER_DESC;