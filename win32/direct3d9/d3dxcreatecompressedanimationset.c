HRESULT D3DXCreateCompressedAnimationSet(
  _In_        LPCSTR                       pName,
  _In_        DOUBLE                       TicksPerSecond,
  _In_        D3DXPLAYBACK_TYPE            Playback,
  _In_        LPD3DXBUFFER                 pCompressedData,
  _In_        UINT                         NumCallbackKeys,
  _In_  const LPD3DXKEY_CALLBACK           *pCallKeys,
  _Out_       LPD3DXCOMPRESSEDANIMATIONSET *ppAnimationSet
);