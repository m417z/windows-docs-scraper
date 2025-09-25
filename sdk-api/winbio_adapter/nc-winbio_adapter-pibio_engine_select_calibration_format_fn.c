PIBIO_ENGINE_SELECT_CALIBRATION_FORMAT_FN PibioEngineSelectCalibrationFormatFn;

HRESULT PibioEngineSelectCalibrationFormatFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [in]      PWINBIO_UUID FormatArray,
  [in]      SIZE_T FormatCount,
  [out]     PWINBIO_UUID SelectedFormat,
  [out]     PSIZE_T MaxBufferSize
)
{...}