PIBIO_ENGINE_EXPORT_ENGINE_DATA_FN PibioEngineExportEngineDataFn;

HRESULT PibioEngineExportEngineDataFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [in]      WINBIO_BIR_DATA_FLAGS Flags,
  [out]     PWINBIO_BIR *SampleBuffer,
  [out]     PSIZE_T SampleSize
)
{...}