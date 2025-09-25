typedef struct _D3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMGPU2 {
  [in] UINT                 ObjectCount;
  [in] const D3DKMT_HANDLE  *ObjectHandleArray;
  [in] D3DDDICB_SIGNALFLAGS Flags;
  [in] ULONG                BroadcastContextCount;
  [in] const D3DKMT_HANDLE  *BroadcastContextArray;
  union {
    [in] D3DKMT_ALIGN64 UINT64 FenceValue;
    [in] HANDLE                CpuEventHandle;
    [in] const UINT64          *MonitoredFenceValueArray;
         D3DKMT_ALIGN64 UINT64 Reserved[8];
  };
} D3DKMT_SIGNALSYNCHRONIZATIONOBJECTFROMGPU2;