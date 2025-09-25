typedef struct D3DDDICB_SIGNALSYNCHRONIZATIONOBJECTFROMCPU {
  [in] UINT                ObjectCount;
  [in] const D3DKMT_HANDLE *ObjectHandleArray;
  [in] const UINT64        *FenceValueArray;
} D3DDDICB_SIGNALSYNCHRONIZATIONOBJECTFROMCPU;