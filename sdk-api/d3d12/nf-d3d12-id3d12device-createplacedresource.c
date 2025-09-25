HRESULT CreatePlacedResource(
  ID3D12Heap                *pHeap,
  UINT64                    HeapOffset,
  const D3D12_RESOURCE_DESC *pDesc,
  D3D12_RESOURCE_STATES     InitialState,
  const D3D12_CLEAR_VALUE   *pOptimizedClearValue,
  REFIID                    riid,
  void                      **ppvResource
);