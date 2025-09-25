EVT_ACX_FACTORY_CIRCUIT_CREATE_CIRCUITDEVICE EvtAcxFactoryCircuitCreateCircuitdevice;

NTSTATUS EvtAcxFactoryCircuitCreateCircuitdevice(
  WDFDEVICE Parent,
  ACXFACTORYCIRCUIT Factory,
  PACX_FACTORY_CIRCUIT_ADD_CIRCUIT Config,
  WDFDEVICE *Device
)
{...}