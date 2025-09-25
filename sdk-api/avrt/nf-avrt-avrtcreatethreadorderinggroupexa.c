AVRTAPI BOOL AvRtCreateThreadOrderingGroupExA(
  [out]          PHANDLE        Context,
  [in]           PLARGE_INTEGER Period,
  [in, out]      GUID           *ThreadOrderingGuid,
  [in, optional] PLARGE_INTEGER Timeout,
  [in]           LPCSTR         TaskName
);