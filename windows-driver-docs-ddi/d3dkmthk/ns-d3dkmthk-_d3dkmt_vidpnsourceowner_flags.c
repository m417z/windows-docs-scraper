typedef struct _D3DKMT_VIDPNSOURCEOWNER_FLAGS {
  union {
    struct {
      UINT AllowOutputDuplication : 1;
      UINT DisableDWMVirtualMode : 1;
      UINT UseNtHandles : 1;
      UINT Reserved : 29;
    };
    UINT Value;
  };
} D3DKMT_VIDPNSOURCEOWNER_FLAGS;