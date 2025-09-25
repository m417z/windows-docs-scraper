typedef struct _HTTP_RESPONSE_HEADERS {
  USHORT               UnknownHeaderCount;
  PHTTP_UNKNOWN_HEADER pUnknownHeaders;
  USHORT               TrailerCount;
  PHTTP_UNKNOWN_HEADER pTrailers;
  HTTP_KNOWN_HEADER    KnownHeaders[HttpHeaderResponseMaximum];
} HTTP_RESPONSE_HEADERS, *PHTTP_RESPONSE_HEADERS;