HTTPAPI_LINKAGE ULONG WINAPI
HttpQueryRequestProperty(
  _In_ HANDLE RequestQueueHandle,
  _In_ HTTP_OPAQUE_ID Id,
  _In_ HTTP_REQUEST_PROPERTY PropertyId,
  _In_reads_bytes_opt_(QualifierSize) VOID *Qualifier,
  _In_ ULONG QualifierSize,
  _Out_writes_bytes_to_opt_(OutputBufferSize, *BytesReturned) PVOID Output,
  _In_ ULONG OutputBufferSize,
  _Out_opt_ PULONG BytesReturned,
  _In_opt_ LPOVERLAPPED Overlapped
);