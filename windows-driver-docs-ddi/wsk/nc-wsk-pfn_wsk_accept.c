PFN_WSK_ACCEPT PfnWskAccept;

NTSTATUS PfnWskAccept(
  [in]            PWSK_SOCKET ListenSocket,
                  ULONG Flags,
  [in, optional]  PVOID AcceptSocketContext,
  [in, optional]  const WSK_CLIENT_CONNECTION_DISPATCH *AcceptSocketDispatch,
  [out, optional] PSOCKADDR LocalAddress,
  [out, optional] PSOCKADDR RemoteAddress,
  [in, out]       PIRP Irp
)
{...}