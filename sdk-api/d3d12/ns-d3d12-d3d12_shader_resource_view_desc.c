typedef struct D3D12_SHADER_RESOURCE_VIEW_DESC {
  DXGI_FORMAT         Format;
  D3D12_SRV_DIMENSION ViewDimension;
  UINT                Shader4ComponentMapping;
  union {
    D3D12_BUFFER_SRV                            Buffer;
    D3D12_TEX1D_SRV                             Texture1D;
    D3D12_TEX1D_ARRAY_SRV                       Texture1DArray;
    D3D12_TEX2D_SRV                             Texture2D;
    D3D12_TEX2D_ARRAY_SRV                       Texture2DArray;
    D3D12_TEX2DMS_SRV                           Texture2DMS;
    D3D12_TEX2DMS_ARRAY_SRV                     Texture2DMSArray;
    D3D12_TEX3D_SRV                             Texture3D;
    D3D12_TEXCUBE_SRV                           TextureCube;
    D3D12_TEXCUBE_ARRAY_SRV                     TextureCubeArray;
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV RaytracingAccelerationStructure;
  };
} D3D12_SHADER_RESOURCE_VIEW_DESC;