typedef struct _D3DDDICB_DEALLOCATE {
  [in] HANDLE              hResource;
  [in] UINT                NumAllocations;
  [in] const D3DKMT_HANDLE *HandleList;
} D3DDDICB_DEALLOCATE;