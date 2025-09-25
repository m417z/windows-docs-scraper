HTTPAPI_LINKAGE ULONG HttpReceiveRequestEntityBody(
  [in]            HANDLE          RequestQueueHandle,
  [in]            HTTP_REQUEST_ID RequestId,
  [in]            ULONG           Flags,
  [out]           PVOID           EntityBuffer,
  [in]            ULONG           EntityBufferLength,
  [out, optional] PULONG          BytesReturned,
  [in, optional]  LPOVERLAPPED    Overlapped
);