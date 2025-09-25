PFN_WSK_SEND_BACKLOG_EVENT PfnWskSendBacklogEvent;

NTSTATUS PfnWskSendBacklogEvent(
  [in, optional] PVOID SocketContext,
  [in]           SIZE_T IdealBacklogSize
)
{...}