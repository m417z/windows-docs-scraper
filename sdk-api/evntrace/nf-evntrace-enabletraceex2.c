ULONG WMIAPI EnableTraceEx2(
                 CONTROLTRACE_ID          TraceId,
  [in]           LPCGUID                  ProviderId,
  [in]           ULONG                    ControlCode,
  [in]           UCHAR                    Level,
  [in]           ULONGLONG                MatchAnyKeyword,
  [in]           ULONGLONG                MatchAllKeyword,
  [in]           ULONG                    Timeout,
  [in, optional] PENABLE_TRACE_PARAMETERS EnableParameters
);