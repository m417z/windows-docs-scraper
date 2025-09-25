typedef struct _D3DKMT_RECLAIMALLOCATIONS2 {
  [in]  D3DKMT_HANDLE         hPagingQueue;
  [in]  UINT                  NumAllocations;
  [in]  D3DKMT_HANDLE         *pResources;
  [in]  const D3DKMT_HANDLE   *HandleList;
  union {
    [out] BOOL                  *pDiscarded;
    [in]  D3DDDI_RECLAIM_RESULT *pResults;
  };
  [out] BOOL                  *pDiscarded;
        D3DKMT_ALIGN64 UINT64 PagingFenceValue;
} D3DKMT_RECLAIMALLOCATIONS2;