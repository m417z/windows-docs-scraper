typedef struct _D3DKMT_OPENSYNCOBJECTFROMNTHANDLE2 {
  [in]  HANDLE                             hNtHandle;
  [in]  D3DKMT_HANDLE                      hDevice;
  [in]  D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS Flags;
  [out] D3DKMT_HANDLE                      hSyncObject;
  union {
    struct {
      VOID                                  *FenceValueCPUVirtualAddress;
      D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS FenceValueGPUVirtualAddress;
      UINT                                  EngineAffinity;
    } MonitoredFence;
          D3DKMT_ALIGN64 UINT64 Reserved[8];
  };
} D3DKMT_OPENSYNCOBJECTFROMNTHANDLE2;