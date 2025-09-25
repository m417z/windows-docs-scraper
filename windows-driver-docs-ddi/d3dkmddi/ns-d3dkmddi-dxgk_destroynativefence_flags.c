typedef struct _DXGK_DESTROYNATIVEFENCE_FLAGS {
  union {
    struct {
      UINT Reserved : 32;
    };
    UINT Value;
  };
} DXGK_DESTROYNATIVEFENCE_FLAGS;