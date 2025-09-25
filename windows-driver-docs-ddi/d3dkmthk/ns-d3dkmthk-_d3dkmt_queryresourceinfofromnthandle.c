typedef struct _D3DKMT_QUERYRESOURCEINFOFROMNTHANDLE {
  [in]  D3DKMT_HANDLE hDevice;
  [in]  HANDLE        hNtHandle;
  [in]  VOID          *pPrivateRuntimeData;
  [in]  UINT          PrivateRuntimeDataSize;
  [out] UINT          TotalPrivateDriverDataSize;
  [out] UINT          ResourcePrivateDriverDataSize;
  [out] UINT          NumAllocations;
} D3DKMT_QUERYRESOURCEINFOFROMNTHANDLE;