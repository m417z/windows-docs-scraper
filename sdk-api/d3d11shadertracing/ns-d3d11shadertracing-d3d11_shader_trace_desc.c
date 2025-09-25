typedef struct D3D11_SHADER_TRACE_DESC {
  D3D11_SHADER_TYPE Type;
  UINT              Flags;
  union {
    D3D11_VERTEX_SHADER_TRACE_DESC   VertexShaderTraceDesc;
    D3D11_HULL_SHADER_TRACE_DESC     HullShaderTraceDesc;
    D3D11_DOMAIN_SHADER_TRACE_DESC   DomainShaderTraceDesc;
    D3D11_GEOMETRY_SHADER_TRACE_DESC GeometryShaderTraceDesc;
    D3D11_PIXEL_SHADER_TRACE_DESC    PixelShaderTraceDesc;
    D3D11_COMPUTE_SHADER_TRACE_DESC  ComputeShaderTraceDesc;
  };
} D3D11_SHADER_TRACE_DESC;