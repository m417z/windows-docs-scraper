PIBIO_ENGINE_CREATE_KEY_FN PibioEngineCreateKeyFn;

HRESULT PibioEngineCreateKeyFn(
  PWINBIO_PIPELINE Pipeline,
  const UCHAR *Key,
  SIZE_T KeySize,
  PUCHAR KeyIdentifier,
  SIZE_T KeyIdentifierSize,
  PSIZE_T ResultSize
)
{...}