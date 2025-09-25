typedef struct _D3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMGPU {
  [in] D3DKMT_HANDLE       hContext;
  [in] UINT                ObjectCount;
  [in] const D3DKMT_HANDLE *ObjectHandleArray;
  union {
    [in] const UINT64          *MonitoredFenceValueArray;
    [in] D3DKMT_ALIGN64 UINT64 FenceValue;
         D3DKMT_ALIGN64 UINT64 Reserved[8];
  };
} D3DKMT_WAITFORSYNCHRONIZATIONOBJECTFROMGPU;