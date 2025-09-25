ULONG WMIAPI EnumerateTraceGuidsEx(
  [in]  TRACE_QUERY_INFO_CLASS TraceQueryInfoClass,
  [in]  PVOID                  InBuffer,
  [in]  ULONG                  InBufferSize,
  [out] PVOID                  OutBuffer,
  [in]  ULONG                  OutBufferSize,
  [out] PULONG                 ReturnLength
);