typedef struct _DXGKARGCB_DISCONNECTDOORBELL_FLAGS {
  union {
    struct {
      UINT Reserved : 32;
    };
    UINT Value;
  };
} DXGKARGCB_DISCONNECTDOORBELL_FLAGS;