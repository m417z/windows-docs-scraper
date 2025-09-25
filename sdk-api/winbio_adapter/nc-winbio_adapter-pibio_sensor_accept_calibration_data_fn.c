PIBIO_SENSOR_ACCEPT_CALIBRATION_DATA_FN PibioSensorAcceptCalibrationDataFn;

HRESULT PibioSensorAcceptCalibrationDataFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [in]      PUCHAR CalibrationBuffer,
  [in]      SIZE_T CalibrationBufferSize
)
{...}