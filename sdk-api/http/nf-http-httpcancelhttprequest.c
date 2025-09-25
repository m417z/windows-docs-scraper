HTTPAPI_LINKAGE ULONG HttpCancelHttpRequest(
  [in]           HANDLE          RequestQueueHandle,
  [in]           HTTP_REQUEST_ID RequestId,
  [in, optional] LPOVERLAPPED    Overlapped
);