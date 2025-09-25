EVT_ACX_CIRCUIT_CREATE_STREAM EvtAcxCircuitCreateStream;

NTSTATUS EvtAcxCircuitCreateStream(
  WDFDEVICE Device,
  ACXCIRCUIT Circuit,
  ACXPIN Pin,
  PACXSTREAM_INIT StreamInit,
  ACXDATAFORMAT StreamFormat,
  const GUID *SignalProcessingMode,
  ACXOBJECTBAG VarArguments
)
{...}