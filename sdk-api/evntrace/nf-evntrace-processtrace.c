ETW_APP_DECLSPEC_DEPRECATED ULONG WMIAPI ProcessTrace(
  [in] PROCESSTRACE_HANDLE *HandleArray,
  [in] ULONG               HandleCount,
  [in] LPFILETIME          StartTime,
  [in] LPFILETIME          EndTime
);