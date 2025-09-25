typedef struct _HTTP_RESPONSE_INFO {
  HTTP_RESPONSE_INFO_TYPE Type;
  ULONG                   Length;
  PVOID                   pInfo;
} HTTP_RESPONSE_INFO, *PHTTP_RESPONSE_INFO;