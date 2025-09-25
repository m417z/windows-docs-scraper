EVT_SPB_CONTROLLER_READ EvtSpbControllerRead;

VOID EvtSpbControllerRead(
  [in] WDFDEVICE Controller,
  [in] SPBTARGET Target,
  [in] SPBREQUEST Request,
  [in] size_t Length
)
{...}