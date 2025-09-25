typedef struct _DXGKARG_CLOSEALLOCATION {
  [in] UINT         NumAllocations;
  [in] const HANDLE *pOpenHandleList;
} DXGKARG_CLOSEALLOCATION;