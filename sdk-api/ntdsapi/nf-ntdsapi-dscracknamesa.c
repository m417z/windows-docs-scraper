NTDSAPI DWORD DsCrackNamesA(
  [in]  HANDLE           hDS,
  [in]  DS_NAME_FLAGS    flags,
  [in]  DS_NAME_FORMAT   formatOffered,
  [in]  DS_NAME_FORMAT   formatDesired,
  [in]  DWORD            cNames,
  [in]  const LPCSTR     *rpNames,
  [out] PDS_NAME_RESULTA *ppResult
);