PIBIO_SENSOR_EXPORT_SENSOR_DATA_FN PibioSensorExportSensorDataFn;

HRESULT PibioSensorExportSensorDataFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [out]     PWINBIO_BIR *SampleBuffer,
  [out]     PSIZE_T SampleSize
)
{...}