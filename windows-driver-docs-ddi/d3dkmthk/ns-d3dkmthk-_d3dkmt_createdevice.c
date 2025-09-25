typedef struct _D3DKMT_CREATEDEVICE {
  union {
    [in]  D3DKMT_HANDLE hAdapter;
    [in]  VOID          *pAdapter;
  };
  [in]  D3DKMT_CREATEDEVICEFLAGS Flags;
  [out] D3DKMT_HANDLE            hDevice;
  [out] VOID                     *pCommandBuffer;
  [out] UINT                     CommandBufferSize;
  [out] D3DDDI_ALLOCATIONLIST    *pAllocationList;
  [out] UINT                     AllocationListSize;
  [out] D3DDDI_PATCHLOCATIONLIST *pPatchLocationList;
  [out] UINT                     PatchLocationListSize;
} D3DKMT_CREATEDEVICE;