typedef struct _HTTP_REQUEST_HEADERS {
  USHORT               UnknownHeaderCount;
  PHTTP_UNKNOWN_HEADER pUnknownHeaders;
  USHORT               TrailerCount;
  PHTTP_UNKNOWN_HEADER pTrailers;
  HTTP_KNOWN_HEADER    KnownHeaders[HttpHeaderRequestMaximum];
} HTTP_REQUEST_HEADERS, *PHTTP_REQUEST_HEADERS;