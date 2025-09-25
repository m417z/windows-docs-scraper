typedef struct _D3D12_SHADER_INPUT_BIND_DESC {
  LPCSTR                   Name;
  D3D_SHADER_INPUT_TYPE    Type;
  UINT                     BindPoint;
  UINT                     BindCount;
  UINT                     uFlags;
  D3D_RESOURCE_RETURN_TYPE ReturnType;
  D3D_SRV_DIMENSION        Dimension;
  UINT                     NumSamples;
  UINT                     Space;
  UINT                     uID;
} D3D12_SHADER_INPUT_BIND_DESC;