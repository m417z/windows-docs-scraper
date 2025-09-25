HTTPAPI_LINKAGE ULONG HttpReadFragmentFromCache(
  [in]  HANDLE           RequestQueueHandle,
  [in]  PCWSTR           UrlPrefix,
  [in]  PHTTP_BYTE_RANGE ByteRange,
  [out] PVOID            Buffer,
  [in]  ULONG            BufferLength,
  [out] PULONG           BytesRead,
  [in]  LPOVERLAPPED     Overlapped
);