typedef struct _D3DDDIARG_CREATEDEVICE {
  [in/out] HANDLE                       hDevice;
  [in]     UINT                         Interface;
  [in]     UINT                         Version;
  [in]     const D3DDDI_DEVICECALLBACKS *pCallbacks;
  [in]     VOID                         *pCommandBuffer;
  [in]     UINT                         CommandBufferSize;
  [in]     D3DDDI_ALLOCATIONLIST        *pAllocationList;
  [in]     UINT                         AllocationListSize;
  [in]     D3DDDI_PATCHLOCATIONLIST     *pPatchLocationList;
  [in]     UINT                         PatchLocationListSize;
           D3DDDI_DEVICEFUNCS           *pDeviceFuncs;
  [in]     D3DDDI_CREATEDEVICEFLAGS     Flags;
           D3DGPU_VIRTUAL_ADDRESS       CommandBuffer;
} D3DDDIARG_CREATEDEVICE;