FWPS_NET_BUFFER_LIST_NOTIFY_FN0 FwpsNetBufferListNotifyFn0;

void FwpsNetBufferListNotifyFn0(
  [in]                FWPS_NET_BUFFER_LIST_EVENT_TYPE0 eventType,
  [in, out, optional] NET_BUFFER_LIST *netBufferList,
  [in, out, optional] NET_BUFFER_LIST *newNetBufferList,
  [in]                UINT16 layerId,
  [in]                UINT64 context,
  [in]                UINT64 contextTag
)
{...}