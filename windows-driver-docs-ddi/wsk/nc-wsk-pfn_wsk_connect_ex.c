PFN_WSK_CONNECT_EX PfnWskConnectEx;

NTSTATUS PfnWskConnectEx(
  [in]           PWSK_SOCKET Socket,
  [in]           PSOCKADDR RemoteAddress,
  [in, optional] PWSK_BUF Buffer,
                 ULONG Flags,
  [in, out]      PIRP Irp
)
{...}