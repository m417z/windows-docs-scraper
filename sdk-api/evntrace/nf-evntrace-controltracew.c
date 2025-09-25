ULONG WMIAPI ControlTraceW(
            CONTROLTRACE_ID         TraceId,
  [in]      LPCWSTR                 InstanceName,
  [in, out] PEVENT_TRACE_PROPERTIES Properties,
  [in]      ULONG                   ControlCode
);