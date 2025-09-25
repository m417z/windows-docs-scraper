EVT_ACX_CIRCUIT_PREPARE_HARDWARE EvtAcxCircuitPrepareHardware;

NTSTATUS EvtAcxCircuitPrepareHardware(
  WDFDEVICE Device,
  ACXCIRCUIT Circuit,
  WDFCMRESLIST ResourcesRaw,
  WDFCMRESLIST ResourcesTranslated
)
{...}