typedef struct _DXGK_RESTOREMEMORYFORHOTUPDATEFLAGS {
  union {
    struct {
      UINT RestoreComplete : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} DXGK_RESTOREMEMORYFORHOTUPDATEFLAGS;