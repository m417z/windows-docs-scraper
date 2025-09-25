typedef struct D3DX11_FFT_BUFFER_INFO {
  UINT NumTempBufferSizes;
  UINT TempBufferFloatSizes[D3DX11_FFT_MAX_TEMP_BUFFERS];
  UINT NumPrecomputeBufferSizes;
  UINT PrecomputeBufferFloatSizes[D3DX11_FFT_MAX_PRECOMPUTE_BUFFERS];
} D3DX11_FFT_BUFFER_INFO;