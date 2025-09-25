typedef struct _D3DKMT_LOCK2 {
  D3DKMT_HANDLE       hDevice;
  D3DKMT_HANDLE       hAllocation;
  D3DDDICB_LOCK2FLAGS Flags;
  PVOID               pData;
} D3DKMT_LOCK2;