NTSTATUS AcxStreamInitAssignAcxRequestPreprocessCallback(
  PACXSTREAM_INIT                   StreamInit,
  EVT_ACX_OBJECT_PREPROCESS_REQUEST EvtObjectAcxRequestPreprocess,
  ACXCONTEXT                        DriverContext,
  ACX_REQUEST_TYPE                  RequestType,
  const GUID                        *Set,
  ULONG                             Id
);