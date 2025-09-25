typedef struct _IO_STATUS_BLOCK64 {
  union {
    NTSTATUS Status;
    PVOID64  Pointer;
  } DUMMYUNIONNAME;
  ULONG64 Information;
} IO_STATUS_BLOCK64;