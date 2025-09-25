EVT_ACX_FACTORY_CIRCUIT_POWER_DOWN EvtAcxFactoryCircuitPowerDown;

NTSTATUS EvtAcxFactoryCircuitPowerDown(
  WDFDEVICE Device,
  ACXFACTORYCIRCUIT Factory,
  WDF_POWER_DEVICE_STATE TargetState
)
{...}