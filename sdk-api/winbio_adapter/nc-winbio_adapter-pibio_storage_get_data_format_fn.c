PIBIO_STORAGE_GET_DATA_FORMAT_FN PibioStorageGetDataFormatFn;

HRESULT PibioStorageGetDataFormatFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [out]     PWINBIO_UUID Format,
  [out]     PWINBIO_VERSION Version
)
{...}