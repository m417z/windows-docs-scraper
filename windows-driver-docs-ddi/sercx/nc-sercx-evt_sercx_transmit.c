EVT_SERCX_TRANSMIT EvtSercxTransmit;

NTSTATUS EvtSercxTransmit(
  [in] WDFDEVICE Device,
  [in] size_t Length
)
{...}