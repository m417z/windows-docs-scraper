PFN_WSK_LISTEN PfnWskListen;

NTSTATUS PfnWskListen(
  [in]      PWSK_SOCKET Socket,
  [in, out] PIRP Irp
)
{...}