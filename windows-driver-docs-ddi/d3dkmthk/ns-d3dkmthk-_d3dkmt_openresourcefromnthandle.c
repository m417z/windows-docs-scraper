typedef struct _D3DKMT_OPENRESOURCEFROMNTHANDLE {
  [in]  D3DKMT_HANDLE              hDevice;
  [in]  HANDLE                     hNtHandle;
  [in]  UINT                       NumAllocations;
  [in]  D3DDDI_OPENALLOCATIONINFO2 *pOpenAllocationInfo2;
  [in]  UINT                       PrivateRuntimeDataSize;
  [in]  VOID                       *pPrivateRuntimeData;
  [in]  UINT                       ResourcePrivateDriverDataSize;
  [in]  VOID                       *pResourcePrivateDriverData;
  [in]  UINT                       TotalPrivateDriverDataBufferSize;
  [in]  VOID                       *pTotalPrivateDriverDataBuffer;
  [out] D3DKMT_HANDLE              hResource;
  [out] D3DKMT_HANDLE              hKeyedMutex;
  [in]  VOID                       *pKeyedMutexPrivateRuntimeDat;
  [in]  UINT                       KeyedMutexPrivateRuntimeDataSize;
  [out] D3DKMT_HANDLE              hSyncObject;
} D3DKMT_OPENRESOURCEFROMNTHANDLE;