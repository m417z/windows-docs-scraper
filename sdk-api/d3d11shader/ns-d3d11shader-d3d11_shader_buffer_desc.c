typedef struct _D3D11_SHADER_BUFFER_DESC {
  LPCSTR           Name;
  D3D_CBUFFER_TYPE Type;
  UINT             Variables;
  UINT             Size;
  UINT             uFlags;
} D3D11_SHADER_BUFFER_DESC;