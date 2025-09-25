typedef struct _BPIO_OUTPUT {
  ULONG           Version;
  ULONG           Size;
  BPIO_OPERATIONS Operation;
  BPIO_OUTFLAGS   OutFlags;
  ULONGLONG       Reserved2;
  union {
    BPIO_RESULTS Enable;
    BPIO_RESULTS Query;
  };
} BPIO_OUTPUT, *PBPIO_OUTPUT;