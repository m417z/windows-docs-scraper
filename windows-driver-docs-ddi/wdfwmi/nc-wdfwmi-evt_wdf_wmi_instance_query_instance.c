EVT_WDF_WMI_INSTANCE_QUERY_INSTANCE EvtWdfWmiInstanceQueryInstance;

NTSTATUS EvtWdfWmiInstanceQueryInstance(
  [in]  WDFWMIINSTANCE WmiInstance,
  [in]  ULONG OutBufferSize,
  [in]  PVOID OutBuffer,
  [out] PULONG BufferUsed
)
{...}