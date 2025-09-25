typedef struct _D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT2 {
  [in] HANDLE               hContext;
  [in] UINT                 ObjectCount;
       D3DKMT_HANDLE        ObjectHandleArray[D3DDDI_MAX_OBJECT_SIGNALED];
  [in] D3DDDICB_SIGNALFLAGS Flags;
  [in] ULONG                BroadcastContextCount;
       HANDLE               BroadcastContext[D3DDDI_MAX_BROADCAST_CONTEXT];
  union {
    [in] UINT64 FenceValue;
    [in] HANDLE CpuEventHandle;
  };
} D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT2;