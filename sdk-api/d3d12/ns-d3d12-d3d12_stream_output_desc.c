typedef struct D3D12_STREAM_OUTPUT_DESC {
  const D3D12_SO_DECLARATION_ENTRY *pSODeclaration;
  UINT                             NumEntries;
  const UINT                       *pBufferStrides;
  UINT                             NumStrides;
  UINT                             RasterizedStream;
} D3D12_STREAM_OUTPUT_DESC;