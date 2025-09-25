typedef struct _D3D12_SHADER_VARIABLE_DESC {
  LPCSTR Name;
  UINT   StartOffset;
  UINT   Size;
  UINT   uFlags;
  LPVOID DefaultValue;
  UINT   StartTexture;
  UINT   TextureSize;
  UINT   StartSampler;
  UINT   SamplerSize;
} D3D12_SHADER_VARIABLE_DESC;