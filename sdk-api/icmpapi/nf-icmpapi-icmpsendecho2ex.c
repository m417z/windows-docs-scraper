IPHLPAPI_DLL_LINKAGE DWORD IcmpSendEcho2Ex(
  [in]           HANDLE                 IcmpHandle,
  [in, optional] HANDLE                 Event,
  [in, optional] PIO_APC_ROUTINE        ApcRoutine,
  [in, optional] PVOID                  ApcContext,
  [in]           IPAddr                 SourceAddress,
  [in]           IPAddr                 DestinationAddress,
  [in]           LPVOID                 RequestData,
  [in]           WORD                   RequestSize,
  [in, optional] PIP_OPTION_INFORMATION RequestOptions,
  [out]          LPVOID                 ReplyBuffer,
  [in]           DWORD                  ReplySize,
  [in]           DWORD                  Timeout
);