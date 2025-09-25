typedef struct _D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT {
  [in] HANDLE               hContext;
  [in] UINT                 ObjectCount;
       D3DKMT_HANDLE        ObjectHandleArray[D3DDDI_MAX_OBJECT_SIGNALED];
  [in] D3DDDICB_SIGNALFLAGS Flags;
} D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT;