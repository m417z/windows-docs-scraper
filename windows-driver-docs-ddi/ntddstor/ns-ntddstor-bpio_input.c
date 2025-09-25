typedef struct _BPIO_INPUT {
  ULONG           Version;
  ULONG           Size;
  BPIO_OPERATIONS Operation;
  BPIO_INFLAGS    InFlags;
  ULONGLONG       Reserved2;
} BPIO_INPUT, *PBPIO_INPUT;