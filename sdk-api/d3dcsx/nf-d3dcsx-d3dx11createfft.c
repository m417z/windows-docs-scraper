HRESULT D3DX11CreateFFT(
        ID3D11DeviceContext    *pDeviceContext,
  [in]  const D3DX11_FFT_DESC  *pDesc,
        UINT                   Flags,
  [out] D3DX11_FFT_BUFFER_INFO *pBufferInfo,
  [out] ID3DX11FFT             **ppFFT
);