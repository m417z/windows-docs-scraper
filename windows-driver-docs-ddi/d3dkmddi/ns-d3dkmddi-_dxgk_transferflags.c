typedef struct _DXGK_TRANSFERFLAGS {
  union {
    struct {
      UINT Swizzle : 1;
      UINT Unswizzle : 1;
      UINT AllocationIsIdle : 1;
      UINT TransferStart : 1;
      UINT TransferEnd : 1;
      UINT Reserved : 27;
    };
    [in] UINT Value;
  };
} DXGK_TRANSFERFLAGS;