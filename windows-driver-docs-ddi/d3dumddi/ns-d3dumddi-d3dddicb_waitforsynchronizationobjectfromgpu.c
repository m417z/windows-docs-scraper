typedef struct D3DDDICB_WAITFORSYNCHRONIZATIONOBJECTFROMGPU {
  [in] HANDLE              hContext;
  [in] UINT                ObjectCount;
  [in] const D3DKMT_HANDLE *ObjectHandleArray;
  union {
    [in] const UINT64 *MonitoredFenceValueArray;
    [in] UINT64       FenceValue;
         UINT64       Reserved[8];
  };
} D3DDDICB_WAITFORSYNCHRONIZATIONOBJECTFROMGPU;