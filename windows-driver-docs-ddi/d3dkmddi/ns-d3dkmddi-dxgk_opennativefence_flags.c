typedef struct _DXGK_OPENNATIVEFENCE_FLAGS {
  union {
    struct {
      UINT Reserved : 32;
    };
    UINT Value;
  };
} DXGK_OPENNATIVEFENCE_FLAGS;