typedef struct _D3DKMT_QUERYRESOURCEINFO {
  [in]     D3DKMT_HANDLE hDevice;
  [in]     D3DKMT_HANDLE hGlobalShare;
  [in]     VOID          *pPrivateRuntimeData;
  [in/out] UINT          PrivateRuntimeDataSize;
  [out]    UINT          TotalPrivateDriverDataSize;
  [out]    UINT          ResourcePrivateDriverDataSize;
  [out]    UINT          NumAllocations;
} D3DKMT_QUERYRESOURCEINFO;