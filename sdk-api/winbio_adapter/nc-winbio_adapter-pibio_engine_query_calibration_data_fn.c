PIBIO_ENGINE_QUERY_CALIBRATION_DATA_FN PibioEngineQueryCalibrationDataFn;

HRESULT PibioEngineQueryCalibrationDataFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [out]     PBOOLEAN DiscardAndRepeatCapture,
  [out]     PUCHAR CalibrationBuffer,
  [out]     PSIZE_T CalibrationBufferSize,
  [in]      SIZE_T MaxBufferSize
)
{...}