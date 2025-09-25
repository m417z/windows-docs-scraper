HTTPAPI_LINKAGE ULONG HttpFlushResponseCache(
  [in] HANDLE       RequestQueueHandle,
  [in] PCWSTR       UrlPrefix,
  [in] ULONG        Flags,
  [in] LPOVERLAPPED Overlapped
);