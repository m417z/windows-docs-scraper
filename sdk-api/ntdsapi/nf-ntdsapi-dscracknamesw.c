NTDSAPI DWORD DsCrackNamesW(
  [in]  HANDLE           hDS,
  [in]  DS_NAME_FLAGS    flags,
  [in]  DS_NAME_FORMAT   formatOffered,
  [in]  DS_NAME_FORMAT   formatDesired,
  [in]  DWORD            cNames,
  [in]  const LPCWSTR    *rpNames,
  [out] PDS_NAME_RESULTW *ppResult
);