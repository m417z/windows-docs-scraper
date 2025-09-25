EVT_UCX_CONTROLLER_STOP_TRACKING_FOR_TIME_SYNC EvtUcxControllerStopTrackingForTimeSync;

VOID EvtUcxControllerStopTrackingForTimeSync(
  [in] UCXCONTROLLER UcxController,
  [in] WDFREQUEST WdfRequest,
  [in] size_t OutputBufferLength,
  [in] size_t InputBufferLength
)
{...}