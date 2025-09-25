typedef struct _D3DKMT_OPENRESOURCE {
  [in]     D3DKMT_HANDLE hDevice;
  [in]     D3DKMT_HANDLE hGlobalShare;
  [in]     UINT          NumAllocations;
  union {
    [in/out] D3DDDI_OPENALLOCATIONINFO  *pOpenAllocationInfo;
             D3DDDI_OPENALLOCATIONINFO2 *pOpenAllocationInfo2;
  };
  [in]     VOID          *pPrivateRuntimeData;
  [in]     UINT          PrivateRuntimeDataSize;
  [in/out] VOID          *pResourcePrivateDriverData;
  [in]     UINT          ResourcePrivateDriverDataSize;
  [in/out] VOID          *pTotalPrivateDriverDataBuffer;
  [in/out] UINT          TotalPrivateDriverDataBufferSize;
  [out]    D3DKMT_HANDLE hResource;
} D3DKMT_OPENRESOURCE;