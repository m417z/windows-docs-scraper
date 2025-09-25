typedef struct D3D12DDIARG_MAKERESIDENT_0001 {
  UINT                           NumAdapters;
  const D3D12DDI_HRTPAGINGQUEUE  *pRTPagingQueue;
  UINT                           NumObjects;
  const D3D12DDI_HANDLE_AND_TYPE *pObjects;
#if ...
  D3DDDI_MAKERESIDENT_FLAGS      Flags;
#else
  union {
    struct {
      UINT CantTrimFurther : 1;
    };
    UINT Value;
  } Flags;
#endif
  UINT64                         *pPagingFenceValue;
  UINT                           WaitMask;
} D3D12DDIARG_MAKERESIDENT_0001;