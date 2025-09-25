EVT_SPB_CONTROLLER_SEQUENCE EvtSpbControllerSequence;

VOID EvtSpbControllerSequence(
  [in] WDFDEVICE Controller,
  [in] SPBTARGET Target,
  [in] SPBREQUEST Request,
  [in] ULONG TransferCount
)
{...}