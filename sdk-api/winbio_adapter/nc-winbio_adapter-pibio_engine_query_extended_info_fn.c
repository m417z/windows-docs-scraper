PIBIO_ENGINE_QUERY_EXTENDED_INFO_FN PibioEngineQueryExtendedInfoFn;

HRESULT PibioEngineQueryExtendedInfoFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [out]     PWINBIO_EXTENDED_ENGINE_INFO EngineInfo,
  [in]      SIZE_T EngineInfoSize
)
{...}