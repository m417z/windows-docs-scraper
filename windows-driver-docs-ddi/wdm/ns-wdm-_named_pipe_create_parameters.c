typedef struct _NAMED_PIPE_CREATE_PARAMETERS {
  ULONG         NamedPipeType;
  ULONG         ReadMode;
  ULONG         CompletionMode;
  ULONG         MaximumInstances;
  ULONG         InboundQuota;
  ULONG         OutboundQuota;
  LARGE_INTEGER DefaultTimeout;
  BOOLEAN       TimeoutSpecified;
} NAMED_PIPE_CREATE_PARAMETERS, *PNAMED_PIPE_CREATE_PARAMETERS;