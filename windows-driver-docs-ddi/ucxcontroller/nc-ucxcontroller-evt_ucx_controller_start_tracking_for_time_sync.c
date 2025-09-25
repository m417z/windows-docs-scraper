EVT_UCX_CONTROLLER_START_TRACKING_FOR_TIME_SYNC EvtUcxControllerStartTrackingForTimeSync;

VOID EvtUcxControllerStartTrackingForTimeSync(
  [in] UCXCONTROLLER UcxController,
  [in] WDFREQUEST WdfRequest,
  [in] size_t OutputBufferLength,
  [in] size_t InputBufferLength
)
{...}