PIBIO_ENGINE_IDENTIFY_FEATURE_SET_FN PibioEngineIdentifyFeatureSetFn;

HRESULT PibioEngineIdentifyFeatureSetFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [out]     PWINBIO_IDENTITY Identity,
  [out]     PWINBIO_BIOMETRIC_SUBTYPE SubFactor,
  [out]     PUCHAR *PayloadBlob,
  [out]     PSIZE_T PayloadBlobSize,
  [out]     PUCHAR *HashValue,
  [out]     PSIZE_T HashSize,
  [out]     PWINBIO_REJECT_DETAIL RejectDetail
)
{...}