EVT_SPB_CONTROLLER_UNLOCK EvtSpbControllerUnlock;

VOID EvtSpbControllerUnlock(
  [in] WDFDEVICE Controller,
  [in] SPBTARGET Target,
  [in] SPBREQUEST UnlockRequest
)
{...}