NTSTATUS AcxCircuitInitAssignAcxRequestPreprocessCallback(
  PACXCIRCUIT_INIT                  CircuitInit,
  PFN_ACX_OBJECT_PREPROCESS_REQUEST EvtObjectAcxRequestPreprocess,
  ACXCONTEXT                        DriverContext,
  ACX_REQUEST_TYPE                  RequestType,
  const GUID                        *Set,
  ULONG                             Id
);