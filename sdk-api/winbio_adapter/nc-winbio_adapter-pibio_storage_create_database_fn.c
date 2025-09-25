PIBIO_STORAGE_CREATE_DATABASE_FN PibioStorageCreateDatabaseFn;

HRESULT PibioStorageCreateDatabaseFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [in]      PWINBIO_UUID DatabaseId,
  [in]      WINBIO_BIOMETRIC_TYPE Factor,
  [in]      PWINBIO_UUID Format,
  [in]      LPCWSTR FilePath,
  [in]      LPCWSTR ConnectString,
  [in]      SIZE_T IndexElementCount,
  [in]      SIZE_T InitialSize
)
{...}