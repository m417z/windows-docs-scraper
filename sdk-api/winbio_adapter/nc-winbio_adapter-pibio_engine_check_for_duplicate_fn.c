PIBIO_ENGINE_CHECK_FOR_DUPLICATE_FN PibioEngineCheckForDuplicateFn;

HRESULT PibioEngineCheckForDuplicateFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [out]     PWINBIO_IDENTITY Identity,
  [out]     PWINBIO_BIOMETRIC_SUBTYPE SubFactor,
  [out]     PBOOLEAN Duplicate
)
{...}