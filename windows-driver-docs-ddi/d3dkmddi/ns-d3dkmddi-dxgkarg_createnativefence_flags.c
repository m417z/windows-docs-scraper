typedef struct _DXGKARG_CREATENATIVEFENCE_FLAGS {
  union {
    struct {
      UINT Reserved : 32;
    };
    UINT Value;
  };
} DXGKARG_CREATENATIVEFENCE_FLAGS;