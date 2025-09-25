typedef struct D3DDDICB_CREATEPAGINGQUEUE {
  [in]  D3DDDI_PAGINGQUEUE_PRIORITY Priority;
  [out] D3DKMT_HANDLE               hPagingQueue;
  [out] D3DKMT_HANDLE               hSyncObject;
  [out] VOID                        *FenceValueCPUVirtualAddress;
  [in]  UINT                        PhysicalAdapterIndex;
} D3DDDICB_CREATEPAGINGQUEUE;