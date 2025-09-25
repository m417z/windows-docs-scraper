PFN_WSK_CLOSE_SOCKET PfnWskCloseSocket;

NTSTATUS PfnWskCloseSocket(
  [in]      PWSK_SOCKET Socket,
  [in, out] PIRP Irp
)
{...}