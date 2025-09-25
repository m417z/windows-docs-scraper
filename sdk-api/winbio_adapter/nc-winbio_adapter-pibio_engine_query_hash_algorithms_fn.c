PIBIO_ENGINE_QUERY_HASH_ALGORITHMS_FN PibioEngineQueryHashAlgorithmsFn;

HRESULT PibioEngineQueryHashAlgorithmsFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [out]     PSIZE_T AlgorithmCount,
  [out]     PSIZE_T AlgorithmBufferSize,
  [out]     PUCHAR *AlgorithmBuffer
)
{...}