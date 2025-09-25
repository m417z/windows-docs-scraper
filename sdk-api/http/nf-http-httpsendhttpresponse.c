HTTPAPI_LINKAGE ULONG HttpSendHttpResponse(
  [in]           HANDLE             RequestQueueHandle,
  [in]           HTTP_REQUEST_ID    RequestId,
  [in]           ULONG              Flags,
  [in]           PHTTP_RESPONSE     HttpResponse,
  [in, optional] PHTTP_CACHE_POLICY CachePolicy,
  [out]          PULONG             BytesSent,
  [in]           PVOID              Reserved1,
  [in]           ULONG              Reserved2,
  [in]           LPOVERLAPPED       Overlapped,
  [in, optional] PHTTP_LOG_DATA     LogData
);