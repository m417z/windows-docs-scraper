PIBIO_STORAGE_CONTROL_UNIT_PRIVILEGED_FN PibioStorageControlUnitPrivilegedFn;

HRESULT PibioStorageControlUnitPrivilegedFn(
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