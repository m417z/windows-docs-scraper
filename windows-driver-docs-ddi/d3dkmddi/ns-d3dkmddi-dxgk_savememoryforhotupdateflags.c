typedef struct _DXGK_SAVEMEMORYFORHOTUPDATEFLAGS {
  union {
    struct {
      UINT CancelHotUpdate : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} DXGK_SAVEMEMORYFORHOTUPDATEFLAGS;