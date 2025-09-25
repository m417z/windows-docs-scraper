HRESULT CreateReservedResource(
  [in]            const D3D12_RESOURCE_DESC *pDesc,
  [in]            D3D12_RESOURCE_STATES     InitialState,
  [in, optional]  const D3D12_CLEAR_VALUE   *pOptimizedClearValue,
  [in]            REFIID                    riid,
  [out, optional] void                      **ppvResource
);