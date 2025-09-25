EVT_SERCX_RECEIVE EvtSercxReceive;

NTSTATUS EvtSercxReceive(
  [in] WDFDEVICE Device,
  [in] size_t Length
)
{...}