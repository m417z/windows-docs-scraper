typedef struct _D3DDDICB_RECLAIMALLOCATIONS3 {
  D3DKMT_HANDLE         PagingQueue;
  UINT                  NumAllocations;
  const HANDLE          *pResources;
  const D3DKMT_HANDLE   *HandleList;
  D3DDDI_RECLAIM_RESULT *pResults;
  UINT64                PagingFenceValue;
} D3DDDICB_RECLAIMALLOCATIONS3;