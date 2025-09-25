typedef struct _D3DKMT_CREATEPAGINGQUEUE {
  [in]  D3DKMT_HANDLE               hDevice;
  [in]  D3DDDI_PAGINGQUEUE_PRIORITY Priority;
  [out] D3DKMT_HANDLE               hPagingQueue;
  [out] D3DKMT_HANDLE               hSyncObject;
  [out] VOID                        *FenceValueCPUVirtualAddress;
  [in]  UINT                        PhysicalAdapterIndex;
} D3DKMT_CREATEPAGINGQUEUE;