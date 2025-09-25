EVT_UCX_CONTROLLER_GET_FRAME_NUMBER_AND_QPC_FOR_TIME_SYNC EvtUcxControllerGetFrameNumberAndQpcForTimeSync;

VOID EvtUcxControllerGetFrameNumberAndQpcForTimeSync(
  [in] UCXCONTROLLER UcxController,
  [in] WDFREQUEST WdfRequest,
  [in] size_t OutputBufferLength,
  [in] size_t InputBufferLength
)
{...}