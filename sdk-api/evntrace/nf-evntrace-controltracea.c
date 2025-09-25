ULONG WMIAPI ControlTraceA(
            CONTROLTRACE_ID         TraceId,
  [in]      LPCSTR                  InstanceName,
  [in, out] PEVENT_TRACE_PROPERTIES Properties,
  [in]      ULONG                   ControlCode
);