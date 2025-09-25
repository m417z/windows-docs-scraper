HTTPAPI_LINKAGE ULONG HttpReceiveHttpRequest(
  [in]            HANDLE          RequestQueueHandle,
  [in]            HTTP_REQUEST_ID RequestId,
  [in]            ULONG           Flags,
  [out]           PHTTP_REQUEST   RequestBuffer,
  [in]            ULONG           RequestBufferLength,
  [out, optional] PULONG          BytesReturned,
  [in, optional]  LPOVERLAPPED    Overlapped
);