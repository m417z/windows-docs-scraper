HRESULT D3D11On12CreateDevice(
  [in]            IUnknown                *pDevice,
                  UINT                    Flags,
  [in, optional]  const D3D_FEATURE_LEVEL *pFeatureLevels,
                  UINT                    FeatureLevels,
  [in, optional]  IUnknown                * const *ppCommandQueues,
                  UINT                    NumQueues,
                  UINT                    NodeMask,
  [out, optional] ID3D11Device            **ppDevice,
  [out, optional] ID3D11DeviceContext     **ppImmediateContext,
  [out, optional] D3D_FEATURE_LEVEL       *pChosenFeatureLevel
);