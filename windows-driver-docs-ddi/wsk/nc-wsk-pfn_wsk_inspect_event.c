PFN_WSK_INSPECT_EVENT PfnWskInspectEvent;

WSK_INSPECT_ACTION PfnWskInspectEvent(
  [in, optional] PVOID SocketContext,
  [in]           PSOCKADDR LocalAddress,
  [in]           PSOCKADDR RemoteAddress,
  [in, optional] PWSK_INSPECT_ID InspectID
)
{...}