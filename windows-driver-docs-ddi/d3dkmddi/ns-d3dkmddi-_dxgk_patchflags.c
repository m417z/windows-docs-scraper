typedef struct _DXGK_PATCHFLAGS {
  union {
    struct {
      UINT Paging : 1;
      UINT Present : 1;
      UINT RedirectedPresent : 1;
      UINT NullRendering : 1;
      UINT Reserved : 28;
    };
    [in] UINT Value;
  };
} DXGK_PATCHFLAGS;