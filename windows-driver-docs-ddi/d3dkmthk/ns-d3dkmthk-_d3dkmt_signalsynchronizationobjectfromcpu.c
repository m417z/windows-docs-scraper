typedef struct _D3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMCPU {
  [in] D3DKMT_HANDLE        hDevice;
  [in] UINT                 ObjectCount;
  [in] const D3DKMT_HANDLE  *ObjectHandleArray;
  [in] const UINT64         *FenceValueArray;
       D3DDDICB_SIGNALFLAGS Flags;
} D3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMCPU;