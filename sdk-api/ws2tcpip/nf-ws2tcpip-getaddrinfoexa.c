INT WSAAPI GetAddrInfoExA(
  [in, optional]  PCSTR                              pName,
  [in, optional]  PCSTR                              pServiceName,
  [in]            DWORD                              dwNameSpace,
  [in, optional]  LPGUID                             lpNspId,
  [in, optional]  const ADDRINFOEXA                  *hints,
  [out]           PADDRINFOEXA                       *ppResult,
  [in, optional]  timeval                            *timeout,
  [in, optional]  LPOVERLAPPED                       lpOverlapped,
  [in, optional]  LPLOOKUPSERVICE_COMPLETION_ROUTINE lpCompletionRoutine,
  [out, optional] LPHANDLE                           lpNameHandle
);