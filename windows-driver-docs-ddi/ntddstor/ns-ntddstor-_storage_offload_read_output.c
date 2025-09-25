typedef struct _STORAGE_OFFLOAD_READ_OUTPUT {
  ULONG                 OffloadReadFlags;
  ULONG                 Reserved;
  ULONGLONG             LengthProtected;
  ULONG                 TokenLength;
  STORAGE_OFFLOAD_TOKEN Token;
} STORAGE_OFFLOAD_READ_OUTPUT, *PSTORAGE_OFFLOAD_READ_OUTPUT;