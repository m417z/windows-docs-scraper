typedef struct _STATUS_BLOCK {
  union {
    VP_STATUS Status;
    PVOID     Pointer;
  };
  ULONG_PTR Information;
} STATUS_BLOCK, *PSTATUS_BLOCK;