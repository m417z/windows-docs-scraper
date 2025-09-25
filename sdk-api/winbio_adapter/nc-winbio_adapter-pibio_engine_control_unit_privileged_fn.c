PIBIO_ENGINE_CONTROL_UNIT_PRIVILEGED_FN PibioEngineControlUnitPrivilegedFn;

HRESULT PibioEngineControlUnitPrivilegedFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [in]      ULONG ControlCode,
  [in]      PUCHAR SendBuffer,
  [in]      SIZE_T SendBufferSize,
  [in]      PUCHAR ReceiveBuffer,
  [in]      SIZE_T ReceiveBufferSize,
  [out]     PSIZE_T ReceiveDataSize,
  [out]     PULONG OperationStatus
)
{...}