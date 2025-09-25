INT WSAAPI SetAddrInfoExA(
  [in]            PCSTR                              pName,
  [in]            PCSTR                              pServiceName,
  [in, out]       SOCKET_ADDRESS                     *pAddresses,
  [in]            DWORD                              dwAddressCount,
  [in, optional]  LPBLOB                             lpBlob,
  [in]            DWORD                              dwFlags,
  [in]            DWORD                              dwNameSpace,
  [in, optional]  LPGUID                             lpNspId,
  [in, optional]  timeval                            *timeout,
  [in, optional]  LPOVERLAPPED                       lpOverlapped,
  [in, optional]  LPLOOKUPSERVICE_COMPLETION_ROUTINE lpCompletionRoutine,
  [out, optional] LPHANDLE                           lpNameHandle
);