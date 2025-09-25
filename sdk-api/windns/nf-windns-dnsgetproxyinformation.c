DWORD DnsGetProxyInformation(
  [in]                PCWSTR                       hostName,
  [in, out]           DNS_PROXY_INFORMATION        *proxyInformation,
  [in, out, optional] DNS_PROXY_INFORMATION        *defaultProxyInformation,
  [in, optional]      DNS_PROXY_COMPLETION_ROUTINE completionRoutine,
  [in, optional]      void                         *completionContext
);