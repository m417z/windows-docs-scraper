PFN_WSK_INSPECT_COMPLETE PfnWskInspectComplete;

NTSTATUS PfnWskInspectComplete(
  [in]      PWSK_SOCKET ListenSocket,
  [in]      PWSK_INSPECT_ID InspectID,
  [in]      WSK_INSPECT_ACTION Action,
  [in, out] PIRP Irp
)
{...}