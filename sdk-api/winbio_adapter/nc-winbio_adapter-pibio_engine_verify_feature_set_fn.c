PIBIO_ENGINE_VERIFY_FEATURE_SET_FN PibioEngineVerifyFeatureSetFn;

HRESULT PibioEngineVerifyFeatureSetFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [in]      PWINBIO_IDENTITY Identity,
  [in]      WINBIO_BIOMETRIC_SUBTYPE SubFactor,
  [out]     PBOOLEAN Match,
  [out]     PUCHAR *PayloadBlob,
  [out]     PSIZE_T PayloadBlobSize,
  [out]     PUCHAR *HashValue,
  [out]     PSIZE_T HashSize,
  [out]     PWINBIO_REJECT_DETAIL RejectDetail
)
{...}