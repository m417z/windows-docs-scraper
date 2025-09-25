FWPS_NET_BUFFER_LIST_NOTIFY_FN1 FwpsNetBufferListNotifyFn1;

NTSTATUS FwpsNetBufferListNotifyFn1(
  [in]                FWPS_NET_BUFFER_LIST_EVENT_TYPE0 eventType,
  [in, out]           NET_BUFFER_LIST *netBufferList,
  [in, out, optional] NET_BUFFER_LIST *newNetBufferList,
  [in]                UINT16 layerId,
  [in]                UINT64 context,
  [in]                UINT64 contextTag
)
{...}