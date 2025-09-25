typedef struct _D3DDDIARG_OPENADAPTER {
  [in/out] HANDLE                        hAdapter;
  [in]     UINT                          Interface;
  [in]     UINT                          Version;
  [in]     const D3DDDI_ADAPTERCALLBACKS *pAdapterCallbacks;
  [out]    D3DDDI_ADAPTERFUNCS           *pAdapterFuncs;
  [out]    UINT                          DriverVersion;
} D3DDDIARG_OPENADAPTER;