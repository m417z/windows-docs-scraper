typedef struct D3DDDI_TRIMRESIDENCYSET_FLAGS {
  union {
    struct {
      UINT PeriodicTrim : 1;
      UINT RestartPeriodicTrim : 1;
      UINT TrimToBudget : 1;
      UINT Reserved : 29;
    };
    UINT Value;
  };
} D3DDDI_TRIMRESIDENCYSET_FLAGS;