PIBIO_STORAGE_QUERY_EXTENDED_INFO_FN PibioStorageQueryExtendedInfoFn;

HRESULT PibioStorageQueryExtendedInfoFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [out]     PWINBIO_EXTENDED_STORAGE_INFO StorageInfo,
  [in]      SIZE_T StorageInfoSize
)
{...}