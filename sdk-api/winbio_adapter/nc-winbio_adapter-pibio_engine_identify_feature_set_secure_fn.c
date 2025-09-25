PIBIO_ENGINE_IDENTIFY_FEATURE_SET_SECURE_FN PibioEngineIdentifyFeatureSetSecureFn;

HRESULT PibioEngineIdentifyFeatureSetSecureFn(
  PWINBIO_PIPELINE Pipeline,
  const UCHAR *Nonce,
  SIZE_T NonceSize,
  const UCHAR *KeyIdentifier,
  SIZE_T KeyIdentifierSize,
  PWINBIO_IDENTITY Identity,
  PWINBIO_BIOMETRIC_SUBTYPE SubFactor,
  PWINBIO_REJECT_DETAIL RejectDetail,
  PUCHAR *Authorization,
  PSIZE_T AuthorizationSize
)
{...}