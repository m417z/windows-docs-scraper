ULONG WMIAPI QueryAllTracesW(
  [out] PEVENT_TRACE_PROPERTIES *PropertyArray,
  [in]  ULONG                   PropertyArrayCount,
  [out] PULONG                  LoggerCount
);