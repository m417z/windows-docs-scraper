IPHLPAPI_DLL_LINKAGE DWORD Icmp6SendEcho2(
  [in]           HANDLE                 IcmpHandle,
  [in, optional] HANDLE                 Event,
  [in, optional] PIO_APC_ROUTINE        ApcRoutine,
  [in, optional] PVOID                  ApcContext,
  [in]           sockaddr_in6           *SourceAddress,
  [in]           sockaddr_in6           *DestinationAddress,
  [in]           LPVOID                 RequestData,
  [in]           WORD                   RequestSize,
  [in, optional] PIP_OPTION_INFORMATION RequestOptions,
  [out]          LPVOID                 ReplyBuffer,
  [in]           DWORD                  ReplySize,
  [in]           DWORD                  Timeout
);