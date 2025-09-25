PFN_WSK_RECEIVE PfnWskReceive;

NTSTATUS PfnWskReceive(
  [in]      PWSK_SOCKET Socket,
  [in]      PWSK_BUF Buffer,
  [in]      ULONG Flags,
  [in, out] PIRP Irp
)
{...}