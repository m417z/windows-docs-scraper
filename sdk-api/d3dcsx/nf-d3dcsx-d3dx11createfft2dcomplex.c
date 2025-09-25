HRESULT D3DX11CreateFFT2DComplex(
        ID3D11DeviceContext    *pDeviceContext,
        UINT                   X,
        UINT                   Y,
        UINT                   Flags,
  [out] D3DX11_FFT_BUFFER_INFO *pBufferInfo,
  [out] ID3DX11FFT             **ppFFT
);