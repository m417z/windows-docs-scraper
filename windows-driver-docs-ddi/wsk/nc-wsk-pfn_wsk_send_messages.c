PFN_WSK_SEND_MESSAGES PfnWskSendMessages;

NTSTATUS PfnWskSendMessages(
  [in]                 PWSK_SOCKET Socket,
  [in]                 PWSK_BUF_LIST BufferList,
                       ULONG Flags,
  [in, optional]       PSOCKADDR RemoteAddress,
  [in]                 ULONG ControlInfoLength,
  [In_reads_bytes_opt] PCMSGHDR ControlInfo,
  [in, out]            PIRP Irp
)
{...}