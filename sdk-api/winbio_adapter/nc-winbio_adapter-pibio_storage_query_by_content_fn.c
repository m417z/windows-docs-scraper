PIBIO_STORAGE_QUERY_BY_CONTENT_FN PibioStorageQueryByContentFn;

HRESULT PibioStorageQueryByContentFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [in]      WINBIO_BIOMETRIC_SUBTYPE SubFactor,
            ULONG IndexVector[],
  [in]      SIZE_T IndexElementCount
)
{...}