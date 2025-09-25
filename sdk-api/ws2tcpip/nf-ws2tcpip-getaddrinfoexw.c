INT WSAAPI GetAddrInfoExW(
  [in, optional]  PCWSTR                             pName,
  [in, optional]  PCWSTR                             pServiceName,
  [in]            DWORD                              dwNameSpace,
  [in, optional]  LPGUID                             lpNspId,
  [in, optional]  const ADDRINFOEXW                  *hints,
  [out]           PADDRINFOEXW                       *ppResult,
  [in, optional]  timeval                            *timeout,
  [in, optional]  LPOVERLAPPED                       lpOverlapped,
  [in, optional]  LPLOOKUPSERVICE_COMPLETION_ROUTINE lpCompletionRoutine,
  [out, optional] LPHANDLE                           lpHandle
);