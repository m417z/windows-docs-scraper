typedef struct _DXGKARG_DISCONNECTDOORBELL_FLAGS {
  union {
    struct {
      UINT Reserved : 32;
    };
    UINT Value;
  };
} DXGKARG_DISCONNECTDOORBELL_FLAGS;