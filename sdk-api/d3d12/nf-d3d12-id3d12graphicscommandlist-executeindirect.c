void ExecuteIndirect(
  [in]           ID3D12CommandSignature *pCommandSignature,
  [in]           UINT                   MaxCommandCount,
  [in]           ID3D12Resource         *pArgumentBuffer,
  [in]           UINT64                 ArgumentBufferOffset,
  [in, optional] ID3D12Resource         *pCountBuffer,
  [in]           UINT64                 CountBufferOffset
);