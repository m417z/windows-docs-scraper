typedef struct _STORAGE_OFFLOAD_TOKEN {
  UCHAR TokenType[4];
  UCHAR Reserved[2];
  UCHAR TokenIdLength[2];
  union {
    struct {
      UCHAR Reserved2[STORAGE_OFFLOAD_TOKEN_ID_LENGTH];
    } StorageOffloadZeroDataToken;
    UCHAR Token[STORAGE_OFFLOAD_TOKEN_ID_LENGTH];
  } DUMMYUNIONNAME;
} STORAGE_OFFLOAD_TOKEN, *PSTORAGE_OFFLOAD_TOKEN;