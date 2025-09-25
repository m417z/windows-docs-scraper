PIBIO_ENGINE_QUERY_PREFERRED_FORMAT_FN PibioEngineQueryPreferredFormatFn;

HRESULT PibioEngineQueryPreferredFormatFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [out]     PWINBIO_REGISTERED_FORMAT StandardFormat,
  [out]     PWINBIO_UUID VendorFormat
)
{...}