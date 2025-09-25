HRESULT CreateHeap1(
  [in]            const D3D12_HEAP_DESC          *pDesc,
  [in, optional]  ID3D12ProtectedResourceSession *pProtectedSession,
  [in]            REFIID                         riid,
  [out, optional] void                           **ppvHeap
);