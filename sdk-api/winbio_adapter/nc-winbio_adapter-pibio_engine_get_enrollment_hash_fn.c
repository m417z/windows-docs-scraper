PIBIO_ENGINE_GET_ENROLLMENT_HASH_FN PibioEngineGetEnrollmentHashFn;

HRESULT PibioEngineGetEnrollmentHashFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [out]     PUCHAR *HashValue,
  [out]     PSIZE_T HashSize
)
{...}