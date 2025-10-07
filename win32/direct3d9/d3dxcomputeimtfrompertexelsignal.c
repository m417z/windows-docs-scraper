HRESULT D3DXComputeIMTFromPerTexelSignal(
  _In_  LPD3DXMESH      pMesh,
  _In_  DWORD           dwTextureIndex,
  _In_  FLOAT           *pfTexelSignal,
  _In_  UINT            uWidth,
  _In_  UINT            uHeight,
  _In_  UINT            uSignalDimension,
  _In_  UINT            uComponents,
  _In_  DWORD           dwOptions,
        LPD3DXUVATLASCB pStatusCallback,
        LPVOID          pUserContext,
  _Out_ LPD3DXBUFFER    *ppIMTData
);