HTTPAPI_LINKAGE ULONG HttpReceiveClientCertificate(
  [in]            HANDLE                     RequestQueueHandle,
  [in]            HTTP_CONNECTION_ID         ConnectionId,
  [in]            ULONG                      Flags,
  [out]           PHTTP_SSL_CLIENT_CERT_INFO SslClientCertInfo,
  [in]            ULONG                      SslClientCertInfoSize,
  [out, optional] PULONG                     BytesReceived,
  [in, optional]  LPOVERLAPPED               Overlapped
);