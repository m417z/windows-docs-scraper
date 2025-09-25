EVT_WDF_WMI_INSTANCE_SET_INSTANCE EvtWdfWmiInstanceSetInstance;

NTSTATUS EvtWdfWmiInstanceSetInstance(
  [in] WDFWMIINSTANCE WmiInstance,
  [in] ULONG InBufferSize,
  [in] PVOID InBuffer
)
{...}