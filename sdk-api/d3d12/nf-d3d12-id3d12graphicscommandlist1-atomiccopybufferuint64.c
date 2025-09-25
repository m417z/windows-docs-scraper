void AtomicCopyBufferUINT64(
  [in] ID3D12Resource                       *pDstBuffer,
       UINT64                               DstOffset,
  [in] ID3D12Resource                       *pSrcBuffer,
       UINT64                               SrcOffset,
       UINT                                 Dependencies,
  [in] ID3D12Resource                       * const *ppDependentResources,
  [in] const D3D12_SUBRESOURCE_RANGE_UINT64 *pDependentSubresourceRanges
);