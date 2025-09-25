PIBIO_STORAGE_DELETE_RECORD_FN PibioStorageDeleteRecordFn;

HRESULT PibioStorageDeleteRecordFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [in]      PWINBIO_IDENTITY Identity,
  [in]      WINBIO_BIOMETRIC_SUBTYPE SubFactor
)
{...}