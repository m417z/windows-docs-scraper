EVT_ACX_FACTORY_CIRCUIT_POWER_UP EvtAcxFactoryCircuitPowerUp;

NTSTATUS EvtAcxFactoryCircuitPowerUp(
  WDFDEVICE Device,
  ACXFACTORYCIRCUIT Factory,
  WDF_POWER_DEVICE_STATE PreviousState
)
{...}