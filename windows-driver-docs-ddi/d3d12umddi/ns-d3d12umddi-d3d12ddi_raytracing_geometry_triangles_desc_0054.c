typedef struct D3D12DDI_RAYTRACING_GEOMETRY_TRIANGLES_DESC_0054 {
  D3D12DDI_GPU_VIRTUAL_ADDRESS            ColumnMajorTransform3x4;
  DXGI_FORMAT                             IndexFormat;
  DXGI_FORMAT                             VertexFormat;
  UINT                                    IndexCount;
  UINT                                    VertexCount;
  D3D12DDI_GPU_VIRTUAL_ADDRESS            IndexBuffer;
  D3D12DDI_GPU_VIRTUAL_ADDRESS_AND_STRIDE VertexBuffer;
} D3D12DDI_RAYTRACING_GEOMETRY_TRIANGLES_DESC_0054;