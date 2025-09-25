IPHLPAPI_DLL_LINKAGE DWORD IcmpSendEcho(
  [in]           HANDLE                 IcmpHandle,
  [in]           IPAddr                 DestinationAddress,
  [in]           LPVOID                 RequestData,
  [in]           WORD                   RequestSize,
  [in, optional] PIP_OPTION_INFORMATION RequestOptions,
  [out]          LPVOID                 ReplyBuffer,
  [in]           DWORD                  ReplySize,
  [in]           DWORD                  Timeout
);