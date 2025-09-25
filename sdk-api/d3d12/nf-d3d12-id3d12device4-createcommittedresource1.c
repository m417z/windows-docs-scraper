HRESULT CreateCommittedResource1(
  [in]            const D3D12_HEAP_PROPERTIES    *pHeapProperties,
  [in]            D3D12_HEAP_FLAGS               HeapFlags,
  [in]            const D3D12_RESOURCE_DESC      *pDesc,
  [in]            D3D12_RESOURCE_STATES          InitialResourceState,
  [in, optional]  const D3D12_CLEAR_VALUE        *pOptimizedClearValue,
  [in, optional]  ID3D12ProtectedResourceSession *pProtectedSession,
  [in]            REFIID                         riidResource,
  [out, optional] void                           **ppvResource
);