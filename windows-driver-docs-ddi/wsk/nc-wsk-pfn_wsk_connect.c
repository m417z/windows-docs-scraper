PFN_WSK_CONNECT PfnWskConnect;

NTSTATUS PfnWskConnect(
  [in]      PWSK_SOCKET Socket,
  [in]      PSOCKADDR RemoteAddress,
            ULONG Flags,
  [in, out] PIRP Irp
)
{...}