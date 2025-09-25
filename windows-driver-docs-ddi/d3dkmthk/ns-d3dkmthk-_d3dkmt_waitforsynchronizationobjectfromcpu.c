typedef struct _D3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMCPU {
  [in] D3DKMT_HANDLE                                    hDevice;
  [in] UINT                                             ObjectCount;
  [in] const D3DKMT_HANDLE                              *ObjectHandleArray;
  [in] const UINT64                                     *FenceValueArray;
  [in] HANDLE                                           hAsyncEvent;
  [in] D3DDDI_WAITFORSYNCHRONIZATIONOBJECTFROMCPU_FLAGS Flags;
} D3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMCPU;