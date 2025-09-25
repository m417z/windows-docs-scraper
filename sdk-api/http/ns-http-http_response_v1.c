typedef struct _HTTP_RESPONSE_V1 {
  ULONG                 Flags;
  HTTP_VERSION          Version;
  USHORT                StatusCode;
  USHORT                ReasonLength;
  PCSTR                 pReason;
  HTTP_RESPONSE_HEADERS Headers;
  USHORT                EntityChunkCount;
  PHTTP_DATA_CHUNK      pEntityChunks;
} HTTP_RESPONSE_V1, *PHTTP_RESPONSE_V1;