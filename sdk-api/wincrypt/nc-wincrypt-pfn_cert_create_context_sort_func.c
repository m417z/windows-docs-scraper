PFN_CERT_CREATE_CONTEXT_SORT_FUNC PfnCertCreateContextSortFunc;

BOOL PfnCertCreateContextSortFunc(
  [in]      DWORD cbTotalEncoded,
  [in]      DWORD cbRemainEncoded,
  [in]      DWORD cEntry,
  [in, out] void *pvSort
)
{...}