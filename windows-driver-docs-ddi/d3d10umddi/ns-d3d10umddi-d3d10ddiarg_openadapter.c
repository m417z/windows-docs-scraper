typedef struct D3D10DDIARG_OPENADAPTER {
  [in]  D3D10DDI_HRTADAPTER           hRTAdapter;
  [out] D3D10DDI_HADAPTER             hAdapter;
  [in]  UINT                          Interface;
  [in]  UINT                          Version;
  [in]  const D3DDDI_ADAPTERCALLBACKS *pAdapterCallbacks;
  union {
    [out] D3D10DDI_ADAPTERFUNCS   *pAdapterFuncs;
    [out] D3D10_2DDI_ADAPTERFUNCS *pAdapterFuncs_2;
  };
} D3D10DDIARG_OPENADAPTER;