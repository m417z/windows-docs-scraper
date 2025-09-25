PIBIO_SENSOR_START_CAPTURE_FN PibioSensorStartCaptureFn;

HRESULT PibioSensorStartCaptureFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [in]      WINBIO_BIR_PURPOSE Purpose,
  [out]     LPOVERLAPPED *Overlapped
)
{...}