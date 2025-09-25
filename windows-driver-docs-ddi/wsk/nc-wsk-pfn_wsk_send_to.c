PFN_WSK_SEND_TO PfnWskSendTo;

NTSTATUS PfnWskSendTo(
  [in]           PWSK_SOCKET Socket,
  [in]           PWSK_BUF Buffer,
                 ULONG Flags,
  [in, optional] PSOCKADDR RemoteAddress,
  [in]           ULONG ControlInfoLength,
  [in, optional] PCMSGHDR ControlInfo,
  [in, out]      PIRP Irp
)
{...}