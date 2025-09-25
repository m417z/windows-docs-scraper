PFN_WSK_RECEIVE_FROM_EVENT PfnWskReceiveFromEvent;

NTSTATUS PfnWskReceiveFromEvent(
  [in, optional] PVOID SocketContext,
  [in]           ULONG Flags,
  [in, optional] PWSK_DATAGRAM_INDICATION DataIndication
)
{...}