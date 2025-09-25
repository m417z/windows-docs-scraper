PFN_WSK_DISCONNECT PfnWskDisconnect;

NTSTATUS PfnWskDisconnect(
  [in]           PWSK_SOCKET Socket,
  [in, optional] PWSK_BUF Buffer,
  [in]           ULONG Flags,
  [in, out]      PIRP Irp
)
{...}