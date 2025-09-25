typedef struct _D3DDDICB_LOCK2 {
  [in]  D3DKMT_HANDLE       hAllocation;
        D3DDDICB_LOCK2FLAGS Flags;
  [out] PVOID               pData;
} D3DDDICB_LOCK2;