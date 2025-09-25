typedef struct _D3DKMT_SIGNALSYNCHRONIZATIONOBJECT2 {
  [in] D3DKMT_HANDLE        hContext;
  [in] UINT                 ObjectCount;
       D3DKMT_HANDLE        ObjectHandleArray[D3DDDI_MAX_OBJECT_SIGNALED];
  [in] D3DDDICB_SIGNALFLAGS Flags;
  [in] ULONG                BroadcastContextCount;
       D3DKMT_HANDLE        BroadcastContext[D3DDDI_MAX_BROADCAST_CONTEXT];
  union {
    struct {
      D3DKMT_ALIGN64 UINT64 FenceValue;
    } Fence;
         HANDLE                CpuEventHandle;
         D3DKMT_ALIGN64 UINT64 Reserved[8];
  };
} D3DKMT_SIGNALSYNCHRONIZATIONOBJECT2;