typedef struct D3D12_BARRIER_GROUP {
  D3D12_BARRIER_TYPE Type;
  UINT32             NumBarriers;
  union {
    const D3D12_GLOBAL_BARRIER  *pGlobalBarriers;
    const D3D12_TEXTURE_BARRIER *pTextureBarriers;
    const D3D12_BUFFER_BARRIER  *pBufferBarriers;
  };
} D3D12_BARRIER_GROUP;