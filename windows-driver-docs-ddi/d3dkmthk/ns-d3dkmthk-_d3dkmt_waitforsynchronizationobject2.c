typedef struct _D3DKMT_WAITFORSYNCHRONIZATIONOBJECT2 {
  [in] D3DKMT_HANDLE hContext;
  [in] UINT          ObjectCount;
       D3DKMT_HANDLE ObjectHandleArray[D3DDDI_MAX_OBJECT_WAITED_ON];
  union {
    struct {
      D3DKMT_ALIGN64 UINT64 FenceValue;
    } Fence;
         D3DKMT_ALIGN64 UINT64 Reserved[8];
  };
} D3DKMT_WAITFORSYNCHRONIZATIONOBJECT2;