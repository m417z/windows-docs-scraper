TCP_OFFLOAD_EVENT_HANDLER TcpOffloadEventHandler;

VOID TcpOffloadEventHandler(
  [in] IN PVOID OffloadContext,
  [in] IN ULONG EventType,
  [in] IN ULONG EventSpecificInformation
)
{...}