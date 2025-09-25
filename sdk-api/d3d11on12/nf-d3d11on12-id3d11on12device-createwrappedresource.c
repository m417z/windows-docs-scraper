HRESULT CreateWrappedResource(
  [in]            IUnknown                   *pResource12,
  [in]            const D3D11_RESOURCE_FLAGS *pFlags11,
                  D3D12_RESOURCE_STATES      InState,
                  D3D12_RESOURCE_STATES      OutState,
                  REFIID                     riid,
  [out, optional] void                       **ppResource11
);