typedef struct _DXVADDI_DECODEBUFFERINFO {
  [out] D3DDDIFORMAT CompressedBufferType;
  [out] UINT         CreationWidth;
  [out] UINT         CreationHeight;
  [out] D3DDDI_POOL  CreationPool;
} DXVADDI_DECODEBUFFERINFO;