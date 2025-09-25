HRESULT CreateVertexBuffer(
  [in]           const D2D1_VERTEX_BUFFER_PROPERTIES        *vertexBufferProperties,
  [in, optional] const GUID                                 *resourceId,
  [in, optional] const D2D1_CUSTOM_VERTEX_BUFFER_PROPERTIES *customVertexBufferProperties,
  [out]          ID2D1VertexBuffer                          **buffer
);