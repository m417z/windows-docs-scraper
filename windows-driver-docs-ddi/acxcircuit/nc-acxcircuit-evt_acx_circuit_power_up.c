EVT_ACX_CIRCUIT_POWER_UP EvtAcxCircuitPowerUp;

NTSTATUS EvtAcxCircuitPowerUp(
  WDFDEVICE Device,
  ACXCIRCUIT Circuit,
  WDF_POWER_DEVICE_STATE PreviousState
)
{...}