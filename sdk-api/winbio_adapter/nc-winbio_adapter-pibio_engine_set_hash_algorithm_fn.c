PIBIO_ENGINE_SET_HASH_ALGORITHM_FN PibioEngineSetHashAlgorithmFn;

HRESULT PibioEngineSetHashAlgorithmFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [in]      SIZE_T AlgorithmBufferSize,
  [in]      PUCHAR AlgorithmBuffer
)
{...}