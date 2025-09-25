PIBIO_SENSOR_QUERY_EXTENDED_INFO_FN PibioSensorQueryExtendedInfoFn;

HRESULT PibioSensorQueryExtendedInfoFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [out]     PWINBIO_EXTENDED_SENSOR_INFO SensorInfo,
  [in]      SIZE_T SensorInfoSize
)
{...}