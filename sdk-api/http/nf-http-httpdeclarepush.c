HTTPAPI_LINKAGE ULONG HttpDeclarePush(
  [in]           HANDLE                RequestQueueHandle,
  [in]           HTTP_REQUEST_ID       RequestId,
  [in]           HTTP_VERB             Verb,
  [in]           PCWSTR                Path,
  [in, optional] PCSTR                 Query,
  [in, optional] PHTTP_REQUEST_HEADERS Headers
);