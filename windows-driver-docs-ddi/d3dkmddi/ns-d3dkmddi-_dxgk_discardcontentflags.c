typedef struct _DXGK_DISCARDCONTENTFLAGS {
  union {
    struct {
      UINT AllocationIsIdle : 1;
      UINT Reserved : 31;
    };
    [in] UINT Value;
  };
} DXGK_DISCARDCONTENTFLAGS;