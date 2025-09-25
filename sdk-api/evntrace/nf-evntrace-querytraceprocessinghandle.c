ETW_APP_DECLSPEC_DEPRECATED ULONG WMIAPI QueryTraceProcessingHandle(
  [in]            PROCESSTRACE_HANDLE          ProcessingHandle,
  [in]            ETW_PROCESS_HANDLE_INFO_TYPE InformationClass,
  [in, optional]  PVOID                        InBuffer,
  [in]            ULONG                        InBufferSize,
  [out, optional] PVOID                        OutBuffer,
  [in]            ULONG                        OutBufferSize,
  [out]           PULONG                       ReturnLength
);