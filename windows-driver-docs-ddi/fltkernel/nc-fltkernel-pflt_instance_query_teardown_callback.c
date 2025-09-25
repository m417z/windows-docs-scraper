PFLT_INSTANCE_QUERY_TEARDOWN_CALLBACK PfltInstanceQueryTeardownCallback;

NTSTATUS PfltInstanceQueryTeardownCallback(
  [in] PCFLT_RELATED_OBJECTS FltObjects,
  [in] FLT_INSTANCE_QUERY_TEARDOWN_FLAGS Flags
)
{...}