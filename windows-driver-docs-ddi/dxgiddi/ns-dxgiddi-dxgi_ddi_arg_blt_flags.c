typedef struct DXGI_DDI_ARG_BLT_FLAGS {
  union {
    struct {
      UINT Resolve : 1;
      UINT Convert : 1;
      UINT Stretch : 1;
      UINT Present : 1;
      UINT Reserved : 28;
    };
    UINT Value;
  };
} DXGI_DDI_ARG_BLT_FLAGS;