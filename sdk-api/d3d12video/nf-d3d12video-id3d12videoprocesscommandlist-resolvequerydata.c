void ResolveQueryData(
  ID3D12QueryHeap  *pQueryHeap,
  D3D12_QUERY_TYPE Type,
  UINT             StartIndex,
  UINT             NumQueries,
  ID3D12Resource   *pDestinationBuffer,
  UINT64           AlignedDestinationBufferOffset
);