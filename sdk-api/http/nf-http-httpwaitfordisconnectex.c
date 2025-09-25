HTTPAPI_LINKAGE ULONG HttpWaitForDisconnectEx(
  [in] HANDLE             RequestQueueHandle,
  [in] HTTP_CONNECTION_ID ConnectionId,
       ULONG              Reserved,
  [in] LPOVERLAPPED       Overlapped
);