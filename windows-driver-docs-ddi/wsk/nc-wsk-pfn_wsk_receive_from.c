PFN_WSK_RECEIVE_FROM PfnWskReceiveFrom;

NTSTATUS PfnWskReceiveFrom(
  [in]            PWSK_SOCKET Socket,
  [in]            PWSK_BUF Buffer,
                  ULONG Flags,
  [out, optional] PSOCKADDR RemoteAddress,
  [in, out]       PULONG ControlLength,
  [out, optional] PCMSGHDR ControlInfo,
  [out, optional] PULONG ControlFlags,
  [in, out]       PIRP Irp
)
{...}