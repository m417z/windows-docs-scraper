typedef struct _ENABLE_TRACE_PARAMETERS_V1 {
  ULONG                    Version;
  ULONG                    EnableProperty;
  ULONG                    ControlFlags;
  GUID                     SourceId;
  PEVENT_FILTER_DESCRIPTOR EnableFilterDesc;
} ENABLE_TRACE_PARAMETERS_V1, *PENABLE_TRACE_PARAMETERS_V1;