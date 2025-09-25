typedef struct _D3DKMT_SUBMITWAITFORSYNCOBJECTSTOHWQUEUE {
  D3DKMT_HANDLE       hHwQueue;
  UINT                ObjectCount;
  const D3DKMT_HANDLE *ObjectHandleArray;
  const UINT64        *FenceValueArray;
} D3DKMT_SUBMITWAITFORSYNCOBJECTSTOHWQUEUE;