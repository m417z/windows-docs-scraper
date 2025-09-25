typedef struct D3D12DDIARG_OPENADAPTER {
  [in]  D3D12DDI_HRTADAPTER           hRTAdapter;
  [out] D3D12DDI_HADAPTER             hAdapter;
  [in]  const D3DDDI_ADAPTERCALLBACKS *pAdapterCallbacks;
  [out] D3D12DDI_ADAPTERFUNCS         *pAdapterFuncs;
} D3D12DDIARG_OPENADAPTER;