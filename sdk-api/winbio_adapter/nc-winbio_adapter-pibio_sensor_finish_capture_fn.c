PIBIO_SENSOR_FINISH_CAPTURE_FN PibioSensorFinishCaptureFn;

HRESULT PibioSensorFinishCaptureFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [out]     PWINBIO_REJECT_DETAIL RejectDetail
)
{...}