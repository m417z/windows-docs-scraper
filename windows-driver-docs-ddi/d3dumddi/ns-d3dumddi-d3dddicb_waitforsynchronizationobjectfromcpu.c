typedef struct D3DDDICB_WAITFORSYNCHRONIZATIONOBJECTFROMCPU {
  [in] UINT                                             ObjectCount;
  [in] const D3DKMT_HANDLE                              *ObjectHandleArray;
  [in] const UINT64                                     *FenceValueArray;
  [in] HANDLE                                           hAsyncEvent;
  [in] D3DDDI_WAITFORSYNCHRONIZATIONOBJECTFROMCPU_FLAGS Flags;
} D3DDDICB_WAITFORSYNCHRONIZATIONOBJECTFROMCPU;