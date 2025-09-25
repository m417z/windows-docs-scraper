typedef struct D3D11DDIARG_CREATEDEFERREDCONTEXT {
  union {
#if ...
    [in/out] D3D11DDI_DEVICEFUNCS             *p11ContextFuncs;
#else
    [in/out] struct D3D11DDI_DEVICEFUNCS      *p11ContextFuncs;
#endif
#if ...
    [in/out] D3D11_1DDI_DEVICEFUNCS           *p11_1ContextFuncs;
#else
    [in/out] struct D3D11_1DDI_DEVICEFUNCS    *p11_1ContextFuncs;
#endif
#if ...
    [in/out] D3DWDDM1_3DDI_DEVICEFUNCS        *pWDDM1_3ContextFuncs;
#else
    [in/out] struct D3DWDDM1_3DDI_DEVICEFUNCS *pWDDM1_3ContextFuncs;
#endif
#if ...
    [in/out] D3DWDDM2_0DDI_DEVICEFUNCS        *pWDDM2_0ContextFuncs;
#else
    [in/out] struct D3DWDDM2_0DDI_DEVICEFUNCS *pWDDM2_0ContextFuncs;
#endif
#if ...
             D3DWDDM2_1DDI_DEVICEFUNCS        *pWDDM2_1ContextFuncs;
#else
             struct D3DWDDM2_1DDI_DEVICEFUNCS *pWDDM2_1ContextFuncs;
#endif
#if ...
             D3DWDDM2_2DDI_DEVICEFUNCS        *pWDDM2_2ContextFuncs;
#else
             struct D3DWDDM2_2DDI_DEVICEFUNCS *pWDDM2_2ContextFuncs;
#endif
#if ...
             D3DWDDM2_6DDI_DEVICEFUNCS        *pWDDM2_6ContextFuncs;
#else
             struct D3DWDDM2_6DDI_DEVICEFUNCS *pWDDM2_6ContextFuncs;
#endif
  };
  [in]     D3D10DDI_HDEVICE      hDrvContext;
  [in]     D3D10DDI_HRTCORELAYER hRTCoreLayer;
  union {
    [in]     const D3D11DDI_CORELAYER_DEVICECALLBACKS      *p11UMCallbacks;
             const D3DWDDM2_0DDI_CORELAYER_DEVICECALLBACKS *pWDDM2_0UMCallbacks;
             const D3DWDDM2_2DDI_CORELAYER_DEVICECALLBACKS *pWDDM2_2UMCallbacks;
             const D3DWDDM2_6DDI_CORELAYER_DEVICECALLBACKS *pWDDM2_6UMCallbacks;
  };
  [in]     UINT                  Flags;
} D3D11DDIARG_CREATEDEFERREDCONTEXT;