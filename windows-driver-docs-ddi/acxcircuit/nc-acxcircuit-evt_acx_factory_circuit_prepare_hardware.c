EVT_ACX_FACTORY_CIRCUIT_PREPARE_HARDWARE EvtAcxFactoryCircuitPrepareHardware;

NTSTATUS EvtAcxFactoryCircuitPrepareHardware(
  WDFDEVICE Device,
  ACXFACTORYCIRCUIT Factory,
  WDFCMRESLIST ResourcesRaw,
  WDFCMRESLIST ResourcesTranslated
)
{...}