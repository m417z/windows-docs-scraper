typedef struct _D3DKMT_SUBMITSIGNALSYNCOBJECTSTOHWQUEUE {
  D3DDDICB_SIGNALFLAGS Flags;
  ULONG                BroadcastHwQueueCount;
  const D3DKMT_HANDLE  *BroadcastHwQueueArray;
  UINT                 ObjectCount;
  const D3DKMT_HANDLE  *ObjectHandleArray;
  const UINT64         *FenceValueArray;
} D3DKMT_SUBMITSIGNALSYNCOBJECTSTOHWQUEUE;