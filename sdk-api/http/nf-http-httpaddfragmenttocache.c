HTTPAPI_LINKAGE ULONG HttpAddFragmentToCache(
  [in]           HANDLE             RequestQueueHandle,
  [in]           PCWSTR             UrlPrefix,
  [in]           PHTTP_DATA_CHUNK   DataChunk,
  [in]           PHTTP_CACHE_POLICY CachePolicy,
  [in, optional] LPOVERLAPPED       Overlapped
);