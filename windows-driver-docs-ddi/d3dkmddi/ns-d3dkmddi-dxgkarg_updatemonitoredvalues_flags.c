typedef struct _DXGKARG_UPDATEMONITOREDVALUES_FLAGS {
  union {
    struct {
      UINT Reserved : 32;
    };
    UINT Value;
  };
} DXGKARG_UPDATEMONITOREDVALUES_FLAGS;