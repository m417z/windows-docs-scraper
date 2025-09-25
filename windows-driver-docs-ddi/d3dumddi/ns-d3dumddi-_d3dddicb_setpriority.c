typedef struct _D3DDDICB_SETPRIORITY {
  [in] HANDLE              hResource;
  [in] UINT                NumAllocations;
  [in] const D3DKMT_HANDLE *HandleList;
  [in] const UINT          *pPriorities;
} D3DDDICB_SETPRIORITY;