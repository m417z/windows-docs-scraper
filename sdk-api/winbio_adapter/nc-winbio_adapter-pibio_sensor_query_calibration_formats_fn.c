PIBIO_SENSOR_QUERY_CALIBRATION_FORMATS_FN PibioSensorQueryCalibrationFormatsFn;

HRESULT PibioSensorQueryCalibrationFormatsFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [out]     PWINBIO_UUID FormatArray,
  [in]      SIZE_T FormatArraySize,
  [out]     PSIZE_T FormatCount
)
{...}