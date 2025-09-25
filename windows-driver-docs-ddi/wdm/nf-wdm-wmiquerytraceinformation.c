NTSTATUS WmiQueryTraceInformation(
  [in]            TRACE_INFORMATION_CLASS TraceInformationClass,
  [out]           PVOID                   TraceInformation,
  [in]            ULONG                   TraceInformationLength,
  [out, optional] PULONG                  RequiredLength,
  [in, optional]  PVOID                   Buffer
);