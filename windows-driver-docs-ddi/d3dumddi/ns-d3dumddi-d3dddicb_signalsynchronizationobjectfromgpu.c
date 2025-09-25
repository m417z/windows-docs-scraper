typedef struct D3DDDICB_SIGNALSYNCHRONIZATIONOBJECTFROMGPU {
  [in] HANDLE              hContext;
  [in] UINT                ObjectCount;
  [in] const D3DKMT_HANDLE *ObjectHandleArray;
  union {
    [in] const UINT64 *MonitoredFenceValueArray;
         UINT64       Reserved[8];
  };
} D3DDDICB_SIGNALSYNCHRONIZATIONOBJECTFROMGPU;