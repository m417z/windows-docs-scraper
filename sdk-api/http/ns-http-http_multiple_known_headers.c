typedef struct _HTTP_MULTIPLE_KNOWN_HEADERS {
  HTTP_HEADER_ID     HeaderId;
  ULONG              Flags;
  USHORT             KnownHeaderCount;
  PHTTP_KNOWN_HEADER KnownHeaders;
} HTTP_MULTIPLE_KNOWN_HEADERS, *PHTTP_MULTIPLE_KNOWN_HEADERS;