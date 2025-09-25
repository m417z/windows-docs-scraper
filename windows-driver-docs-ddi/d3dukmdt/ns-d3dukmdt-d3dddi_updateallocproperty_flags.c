typedef struct D3DDDI_UPDATEALLOCPROPERTY_FLAGS {
  union {
    struct {
      UINT AccessedPhysically : 1;
      UINT Unmoveable : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} D3DDDI_UPDATEALLOCPROPERTY_FLAGS;