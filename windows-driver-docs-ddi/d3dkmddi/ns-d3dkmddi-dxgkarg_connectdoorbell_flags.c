typedef struct _DXGKARG_CONNECTDOORBELL_FLAGS {
  union {
    struct {
      UINT RequireSecondaryAddress : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} DXGKARG_CONNECTDOORBELL_FLAGS;