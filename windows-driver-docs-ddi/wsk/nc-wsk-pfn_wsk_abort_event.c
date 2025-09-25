PFN_WSK_ABORT_EVENT PfnWskAbortEvent;

NTSTATUS PfnWskAbortEvent(
  [in, optional] PVOID SocketContext,
  [in]           PWSK_INSPECT_ID InspectID
)
{...}