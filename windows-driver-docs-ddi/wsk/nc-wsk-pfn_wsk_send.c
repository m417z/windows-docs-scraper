PFN_WSK_SEND PfnWskSend;

NTSTATUS PfnWskSend(
  [in]      PWSK_SOCKET Socket,
  [in]      PWSK_BUF Buffer,
  [in]      ULONG Flags,
  [in, out] PIRP Irp
)
{...}