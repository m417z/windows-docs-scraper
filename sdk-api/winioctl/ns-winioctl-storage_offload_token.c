typedef struct _STORAGE_OFFLOAD_TOKEN {
  BYTE  TokenType[4];
  BYTE  Reserved[2];
  BYTE  TokenIdLength[2];
  union {
    struct {
      BYTE Reserved2[STORAGE_OFFLOAD_TOKEN_ID_LENGTH];
    } StorageOffloadZeroDataToken;
    BYTE Token[STORAGE_OFFLOAD_TOKEN_ID_LENGTH];
  } DUMMYUNIONNAME;
} STORAGE_OFFLOAD_TOKEN, *PSTORAGE_OFFLOAD_TOKEN;