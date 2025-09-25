PFN_WSK_BIND PfnWskBind;

NTSTATUS PfnWskBind(
  [in]      PWSK_SOCKET Socket,
  [in]      PSOCKADDR LocalAddress,
            ULONG Flags,
  [in, out] PIRP Irp
)
{...}