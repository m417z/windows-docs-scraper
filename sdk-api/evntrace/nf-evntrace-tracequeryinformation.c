ULONG WMIAPI TraceQueryInformation(
                  CONTROLTRACE_ID  TraceId,
  [in]            TRACE_INFO_CLASS InformationClass,
  [out]           PVOID            TraceInformation,
  [in]            ULONG            InformationLength,
  [out, optional] PULONG           ReturnLength
);