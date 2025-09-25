PIBIO_STORAGE_ERASE_DATABASE_FN PibioStorageEraseDatabaseFn;

HRESULT PibioStorageEraseDatabaseFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [in]      PWINBIO_UUID DatabaseId,
  [in]      LPCWSTR FilePath,
  [in]      LPCWSTR ConnectString
)
{...}