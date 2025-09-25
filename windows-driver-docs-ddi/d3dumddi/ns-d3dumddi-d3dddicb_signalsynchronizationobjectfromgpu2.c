typedef struct D3DDDICB_SIGNALSYNCHRONIZATIONOBJECTFROMGPU2 {
  [in] UINT                 ObjectCount;
  [in] const D3DKMT_HANDLE  *ObjectHandleArray;
  [in] D3DDDICB_SIGNALFLAGS Flags;
  [in] ULONG                BroadcastContextCount;
  [in] const HANDLE         *BroadcastContextArray;
  union {
    [in] UINT64       FenceValue;
    [in] HANDLE       CpuEventHandle;
    [in] const UINT64 *MonitoredFenceValueArray;
         UINT64       Reserved[8];
  };
} D3DDDICB_SIGNALSYNCHRONIZATIONOBJECTFROMGPU2;