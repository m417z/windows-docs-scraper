HTTPAPI_LINKAGE ULONG HttpSendResponseEntityBody(
  [in]           HANDLE           RequestQueueHandle,
  [in]           HTTP_REQUEST_ID  RequestId,
  [in]           ULONG            Flags,
  [in]           USHORT           EntityChunkCount,
  [in]           PHTTP_DATA_CHUNK EntityChunks,
  [out]          PULONG           BytesSent,
  [in]           PVOID            Reserved1,
  [in]           ULONG            Reserved2,
  [in]           LPOVERLAPPED     Overlapped,
  [in, optional] PHTTP_LOG_DATA   LogData
);