typedef struct DXGI_SWAP_CHAIN_DESC1 {
  UINT             Width;
  UINT             Height;
  DXGI_FORMAT      Format;
  BOOL             Stereo;
  DXGI_SAMPLE_DESC SampleDesc;
  DXGI_USAGE       BufferUsage;
  UINT             BufferCount;
  DXGI_SCALING     Scaling;
  DXGI_SWAP_EFFECT SwapEffect;
  DXGI_ALPHA_MODE  AlphaMode;
  UINT             Flags;
} DXGI_SWAP_CHAIN_DESC1;