PFN_WSK_DISCONNECT_EVENT PfnWskDisconnectEvent;

NTSTATUS PfnWskDisconnectEvent(
  [in, optional] PVOID SocketContext,
  [in]           ULONG Flags
)
{...}