EVT_ACX_CIRCUIT_POWER_DOWN EvtAcxCircuitPowerDown;

NTSTATUS EvtAcxCircuitPowerDown(
  WDFDEVICE Device,
  ACXCIRCUIT Circuit,
  WDF_POWER_DEVICE_STATE TargetState
)
{...}