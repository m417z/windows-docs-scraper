typedef struct _DXGKARGCB_ISFEATUREENABLED2_FLAGS {
  union {
    struct {
      UINT32 Reserved : 32;
    };
    UINT32 Value;
  };
} DXGKARGCB_ISFEATUREENABLED2_FLAGS;