HRESULT CreateDeviceContextState(
                  UINT                    Flags,
  [in]            const D3D_FEATURE_LEVEL *pFeatureLevels,
                  UINT                    FeatureLevels,
                  UINT                    SDKVersion,
                  REFIID                  EmulatedInterface,
  [out, optional] D3D_FEATURE_LEVEL       *pChosenFeatureLevel,
  [out, optional] ID3DDeviceContextState  **ppContextState
);