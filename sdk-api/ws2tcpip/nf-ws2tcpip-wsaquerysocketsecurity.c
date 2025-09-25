INT WSAAPI WSAQuerySocketSecurity(
  [in]            SOCKET                               Socket,
  [in, optional]  const SOCKET_SECURITY_QUERY_TEMPLATE *SecurityQueryTemplate,
  [in]            ULONG                                SecurityQueryTemplateLen,
  [out, optional] SOCKET_SECURITY_QUERY_INFO           *SecurityQueryInfo,
  [in, out]       ULONG                                *SecurityQueryInfoLen,
  [in, optional]  LPWSAOVERLAPPED                      Overlapped,
  [in, optional]  LPWSAOVERLAPPED_COMPLETION_ROUTINE   CompletionRoutine
);