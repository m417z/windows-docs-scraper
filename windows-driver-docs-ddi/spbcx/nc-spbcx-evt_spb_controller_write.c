EVT_SPB_CONTROLLER_WRITE EvtSpbControllerWrite;

VOID EvtSpbControllerWrite(
  [in] WDFDEVICE Controller,
  [in] SPBTARGET Target,
  [in] SPBREQUEST Request,
  [in] size_t Length
)
{...}