PIBIO_SENSOR_PUSH_DATA_TO_ENGINE_FN PibioSensorPushDataToEngineFn;

HRESULT PibioSensorPushDataToEngineFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [in]      WINBIO_BIR_PURPOSE Purpose,
  [in]      WINBIO_BIR_DATA_FLAGS Flags,
  [out]     PWINBIO_REJECT_DETAIL RejectDetail
)
{...}