EVT_UCX_CONTROLLER_GET_TRANSPORT_CHARACTERISTICS EvtUcxControllerGetTransportCharacteristics;

NTSTATUS EvtUcxControllerGetTransportCharacteristics(
  [in]  UCXCONTROLLER UcxController,
  [out] PUCX_CONTROLLER_TRANSPORT_CHARACTERISTICS UcxControllerTransportCharacteristics
)
{...}