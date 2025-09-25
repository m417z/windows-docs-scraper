typedef struct _DXGK_PREEMPTCOMMANDFLAGS {
  union {
    struct {
      UINT Reserved : 32;
    };
    UINT Value;
  };
} DXGK_PREEMPTCOMMANDFLAGS;