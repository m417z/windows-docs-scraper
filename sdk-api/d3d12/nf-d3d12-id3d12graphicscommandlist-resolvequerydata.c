void ResolveQueryData(
  [in] ID3D12QueryHeap  *pQueryHeap,
  [in] D3D12_QUERY_TYPE Type,
  [in] UINT             StartIndex,
  [in] UINT             NumQueries,
  [in] ID3D12Resource   *pDestinationBuffer,
  [in] UINT64           AlignedDestinationBufferOffset
);