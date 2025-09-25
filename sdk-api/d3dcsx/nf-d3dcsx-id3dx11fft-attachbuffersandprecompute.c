HRESULT AttachBuffersAndPrecompute(
  [in] UINT                      NumTempBuffers,
  [in] ID3D11UnorderedAccessView * const *ppTempBuffers,
  [in] UINT                      NumPrecomputeBuffers,
  [in] ID3D11UnorderedAccessView * const *ppPrecomputeBufferSizes
);