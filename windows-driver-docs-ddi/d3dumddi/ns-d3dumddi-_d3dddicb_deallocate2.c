typedef struct _D3DDDICB_DEALLOCATE2 {
  [in] HANDLE                           hResource;
  [in] UINT                             NumAllocations;
  [in] const D3DKMT_HANDLE              *HandleList;
  [in] D3DDDICB_DESTROYALLOCATION2FLAGS Flags;
} D3DDDICB_DEALLOCATE2;