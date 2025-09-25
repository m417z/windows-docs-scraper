HRESULT CreatePlacedResource2(
  ID3D12Heap                 *pHeap,
  UINT64                     HeapOffset,
  const D3D12_RESOURCE_DESC1 *pDesc,
  D3D12_BARRIER_LAYOUT       InitialLayout,
  const D3D12_CLEAR_VALUE    *pOptimizedClearValue,
  UINT32                     NumCastableFormats,
  const DXGI_FORMAT          *pCastableFormats,
  REFIID                     riid,
  void                       **ppvResource
);