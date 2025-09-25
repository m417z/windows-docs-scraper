HTTPAPI_LINKAGE ULONG HttpQueryServiceConfiguration(
  [in]                HANDLE                 ServiceHandle,
  [in]                HTTP_SERVICE_CONFIG_ID ConfigId,
  [in, optional]      PVOID                  pInput,
  [in, optional]      ULONG                  InputLength,
  [in, out, optional] PVOID                  pOutput,
  [in, optional]      ULONG                  OutputLength,
  [out, optional]     PULONG                 pReturnLength,
  [in]                LPOVERLAPPED           pOverlapped
);