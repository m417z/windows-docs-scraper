typedef struct _DXGK_SETPOINTERPOSITIONFLAGS {
  union {
    struct {
      UINT Visible : 1;
      UINT Procedural : 1;
      UINT Reserved : 30;
    };
    [in] UINT Value;
  };
} DXGK_SETPOINTERPOSITIONFLAGS;