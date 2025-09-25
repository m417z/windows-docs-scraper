PFN_WSK_SOCKET PfnWskSocket;

NTSTATUS PfnWskSocket(
  [in]           PWSK_CLIENT Client,
  [in]           ADDRESS_FAMILY AddressFamily,
  [in]           USHORT SocketType,
  [in]           ULONG Protocol,
  [in]           ULONG Flags,
  [in, optional] PVOID SocketContext,
  [in, optional] const VOID *Dispatch,
  [in, optional] PEPROCESS OwningProcess,
  [in, optional] PETHREAD OwningThread,
  [in, optional] PSECURITY_DESCRIPTOR SecurityDescriptor,
  [in, out]      PIRP Irp
)
{...}