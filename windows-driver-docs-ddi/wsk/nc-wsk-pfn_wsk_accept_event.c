PFN_WSK_ACCEPT_EVENT PfnWskAcceptEvent;

NTSTATUS PfnWskAcceptEvent(
  [in, optional] PVOID SocketContext,
  [in]           ULONG Flags,
  [in]           PSOCKADDR LocalAddress,
  [in]           PSOCKADDR RemoteAddress,
  [in, optional] PWSK_SOCKET AcceptSocket,
  [out]          PVOID *AcceptSocketContext,
  [out]          const WSK_CLIENT_CONNECTION_DISPATCH **AcceptSocketDispatch
)
{...}