PIBIO_ENGINE_ACCEPT_SAMPLE_DATA_FN PibioEngineAcceptSampleDataFn;

HRESULT PibioEngineAcceptSampleDataFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [in]      PWINBIO_BIR SampleBuffer,
  [in]      SIZE_T SampleSize,
  [in]      WINBIO_BIR_PURPOSE Purpose,
  [out]     PWINBIO_REJECT_DETAIL RejectDetail
)
{...}