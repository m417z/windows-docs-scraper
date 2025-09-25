PFN_WSK_SOCKET_CONNECT PfnWskSocketConnect;

NTSTATUS PfnWskSocketConnect(
  [in]           PWSK_CLIENT Client,
  [in]           USHORT SocketType,
  [in]           ULONG Protocol,
  [in]           PSOCKADDR LocalAddress,
  [in]           PSOCKADDR RemoteAddress,
                 ULONG Flags,
  [in, optional] PVOID SocketContext,
  [in, optional] const WSK_CLIENT_CONNECTION_DISPATCH *Dispatch,
  [in, optional] PEPROCESS OwningProcess,
  [in, optional] PETHREAD OwningThread,
  [in, optional] PSECURITY_DESCRIPTOR SecurityDescriptor,
  [in, out]      PIRP Irp
)
{...}