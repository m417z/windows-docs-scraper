HTTPAPI_LINKAGE ULONG HttpSetRequestProperty(
  [in] HANDLE                RequestQueueHandle,
  [in] HTTP_OPAQUE_ID        Id,
  [in] HTTP_REQUEST_PROPERTY PropertyId,
  [in] PVOID                 Input,
  [in] ULONG                 InputPropertySize,
  [in] LPOVERLAPPED          Overlapped
);