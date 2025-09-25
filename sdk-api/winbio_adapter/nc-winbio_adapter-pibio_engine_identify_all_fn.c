PIBIO_ENGINE_IDENTIFY_ALL_FN PibioEngineIdentifyAllFn;

HRESULT PibioEngineIdentifyAllFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [out]     PSIZE_T PresenceCount,
  [out]     PWINBIO_PRESENCE *PresenceArray
)
{...}