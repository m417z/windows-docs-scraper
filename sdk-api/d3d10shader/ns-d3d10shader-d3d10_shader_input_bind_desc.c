typedef struct _D3D10_SHADER_INPUT_BIND_DESC {
  LPCSTR                     Name;
  D3D10_SHADER_INPUT_TYPE    Type;
  UINT                       BindPoint;
  UINT                       BindCount;
  UINT                       uFlags;
  D3D10_RESOURCE_RETURN_TYPE ReturnType;
  D3D10_SRV_DIMENSION        Dimension;
  UINT                       NumSamples;
} D3D10_SHADER_INPUT_BIND_DESC;