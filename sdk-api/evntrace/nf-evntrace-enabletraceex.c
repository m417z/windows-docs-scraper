ULONG WMIAPI EnableTraceEx(
  [in]           LPCGUID                  ProviderId,
  [in, optional] LPCGUID                  SourceId,
                 CONTROLTRACE_ID          TraceId,
  [in]           ULONG                    IsEnabled,
  [in]           UCHAR                    Level,
  [in]           ULONGLONG                MatchAnyKeyword,
  [in]           ULONGLONG                MatchAllKeyword,
  [in]           ULONG                    EnableProperty,
  [in, optional] PEVENT_FILTER_DESCRIPTOR EnableFilterDesc
);