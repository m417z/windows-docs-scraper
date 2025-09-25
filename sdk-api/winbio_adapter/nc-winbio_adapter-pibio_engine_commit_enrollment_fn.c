PIBIO_ENGINE_COMMIT_ENROLLMENT_FN PibioEngineCommitEnrollmentFn;

HRESULT PibioEngineCommitEnrollmentFn(
  [in, out]      PWINBIO_PIPELINE Pipeline,
  [in]           PWINBIO_IDENTITY Identity,
  [in]           WINBIO_BIOMETRIC_SUBTYPE SubFactor,
  [in, optional] PUCHAR PayloadBlob,
  [in]           SIZE_T PayloadBlobSize
)
{...}