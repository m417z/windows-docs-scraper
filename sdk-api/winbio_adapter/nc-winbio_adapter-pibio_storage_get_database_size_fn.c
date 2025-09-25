PIBIO_STORAGE_GET_DATABASE_SIZE_FN PibioStorageGetDatabaseSizeFn;

HRESULT PibioStorageGetDatabaseSizeFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [out]     PSIZE_T AvailableRecordCount,
  [out]     PSIZE_T TotalRecordCount
)
{...}