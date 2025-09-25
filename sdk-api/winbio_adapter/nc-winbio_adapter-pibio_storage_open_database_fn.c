PIBIO_STORAGE_OPEN_DATABASE_FN PibioStorageOpenDatabaseFn;

HRESULT PibioStorageOpenDatabaseFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [in]      PWINBIO_UUID DatabaseId,
  [in]      LPCWSTR FilePath,
  [in]      LPCWSTR ConnectString
)
{...}