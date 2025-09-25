HRESULT SetVertexProcessing(
  [in, optional] ID2D1VertexBuffer            *vertexBuffer,
                 D2D1_VERTEX_OPTIONS          vertexOptions,
  [in, optional] const D2D1_BLEND_DESCRIPTION *blendDescription,
  [in, optional] const D2D1_VERTEX_RANGE      *vertexRange,
                 const GUID                   *vertexShader
);