PIBIO_SENSOR_CONTROL_UNIT_FN PibioSensorControlUnitFn;

HRESULT PibioSensorControlUnitFn(
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