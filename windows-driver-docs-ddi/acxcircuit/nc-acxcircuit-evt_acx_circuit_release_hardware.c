EVT_ACX_CIRCUIT_RELEASE_HARDWARE EvtAcxCircuitReleaseHardware;

NTSTATUS EvtAcxCircuitReleaseHardware(
  WDFDEVICE Device,
  ACXCIRCUIT Circuit,
  WDFCMRESLIST ResourcesTranslated
)
{...}