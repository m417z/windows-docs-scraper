EVT_SPB_CONTROLLER_OTHER EvtSpbControllerOther;

VOID EvtSpbControllerOther(
  [in] WDFDEVICE Controller,
  [in] SPBTARGET Target,
  [in] SPBREQUEST Request,
  [in] size_t OutputBufferLength,
  [in] size_t InputBufferLength,
  [in] ULONG IoControlCode
)
{...}