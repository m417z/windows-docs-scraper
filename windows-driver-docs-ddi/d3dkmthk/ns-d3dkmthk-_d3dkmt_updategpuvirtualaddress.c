typedef struct _D3DKMT_UPDATEGPUVIRTUALADDRESS {
  D3DKMT_HANDLE                            hDevice;
  D3DKMT_HANDLE                            hContext;
  D3DKMT_HANDLE                            hFenceObject;
  UINT                                     NumOperations;
  D3DDDI_UPDATEGPUVIRTUALADDRESS_OPERATION *Operations;
  D3DKMT_ALIGN64 D3DKMT_SIZE_T             Reserved0;
  D3DKMT_ALIGN64 UINT64                    Reserved1;
  D3DKMT_ALIGN64 UINT64                    FenceValue;
  union {
    struct {
      UINT DoNotWait : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  } Flags;
} D3DKMT_UPDATEGPUVIRTUALADDRESS;