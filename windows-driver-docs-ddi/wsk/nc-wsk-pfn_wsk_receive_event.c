PFN_WSK_RECEIVE_EVENT PfnWskReceiveEvent;

NTSTATUS PfnWskReceiveEvent(
  [in, optional] PVOID SocketContext,
  [in]           ULONG Flags,
  [in, optional] PWSK_DATA_INDICATION DataIndication,
  [in]           SIZE_T BytesIndicated,
  [in, out]      SIZE_T *BytesAccepted
)
{...}