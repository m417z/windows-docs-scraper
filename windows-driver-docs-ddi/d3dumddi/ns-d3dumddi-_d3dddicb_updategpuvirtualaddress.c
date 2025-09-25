typedef struct _D3DDDICB_UPDATEGPUVIRTUALADDRESS {
  HANDLE                                   hContext;
  D3DKMT_HANDLE                            hFenceObject;
  UINT                                     NumOperations;
  D3DDDI_UPDATEGPUVIRTUALADDRESS_OPERATION *Operations;
  UINT                                     Reserved0;
  UINT64                                   Reserved1;
  UINT64                                   FenceValue;
  union {
    struct {
      UINT DoNotWait : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  } Flags;
} D3DDDICB_UPDATEGPUVIRTUALADDRESS;