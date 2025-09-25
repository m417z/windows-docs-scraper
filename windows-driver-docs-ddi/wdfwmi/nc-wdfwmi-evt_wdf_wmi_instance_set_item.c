EVT_WDF_WMI_INSTANCE_SET_ITEM EvtWdfWmiInstanceSetItem;

NTSTATUS EvtWdfWmiInstanceSetItem(
  [in] WDFWMIINSTANCE WmiInstance,
  [in] ULONG DataItemId,
  [in] ULONG InBufferSize,
  [in] PVOID InBuffer
)
{...}