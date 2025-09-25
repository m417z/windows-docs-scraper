typedef struct D3D12DDIARG_EVICT {
  UINT                           NumObjects;
  const D3D12DDI_HANDLE_AND_TYPE *pObjects;
#if ...
  D3DDDI_EVICT_FLAGS             Flags;
#else
  union {
    struct {
      UINT EvictOnlyIfNecessary : 1;
    };
    UINT Value;
  } Flags;
#endif
} D3D12DDIARG_EVICT;