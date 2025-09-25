typedef struct _STORAGE_OFFLOAD_READ_OUTPUT {
  DWORD                 OffloadReadFlags;
  DWORD                 Reserved;
  DWORDLONG             LengthProtected;
  DWORD                 TokenLength;
  STORAGE_OFFLOAD_TOKEN Token;
} STORAGE_OFFLOAD_READ_OUTPUT, *PSTORAGE_OFFLOAD_READ_OUTPUT;