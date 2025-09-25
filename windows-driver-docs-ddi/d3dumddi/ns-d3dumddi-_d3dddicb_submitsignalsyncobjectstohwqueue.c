typedef struct _D3DDDICB_SUBMITSIGNALSYNCOBJECTSTOHWQUEUE {
  D3DDDICB_SIGNALFLAGS Flags;
  ULONG                BroadcastHwQueueCount;
  const HANDLE         *BroadcastHwQueueArray;
  UINT                 ObjectCount;
  const D3DKMT_HANDLE  *ObjectHandleArray;
  const UINT64         *FenceValueArray;
} D3DDDICB_SUBMITSIGNALSYNCOBJECTSTOHWQUEUE;