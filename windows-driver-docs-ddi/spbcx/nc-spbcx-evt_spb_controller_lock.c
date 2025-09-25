EVT_SPB_CONTROLLER_LOCK EvtSpbControllerLock;

VOID EvtSpbControllerLock(
  [in] WDFDEVICE Controller,
  [in] SPBTARGET Target,
  [in] SPBREQUEST LockRequest
)
{...}