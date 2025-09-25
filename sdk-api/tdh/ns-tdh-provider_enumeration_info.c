typedef struct _PROVIDER_ENUMERATION_INFO {
  ULONG               NumberOfProviders;
  ULONG               Reserved;
  TRACE_PROVIDER_INFO TraceProviderInfoArray[ANYSIZE_ARRAY];
} PROVIDER_ENUMERATION_INFO;