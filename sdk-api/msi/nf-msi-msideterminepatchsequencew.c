UINT MsiDeterminePatchSequenceW(
  [in]           LPCWSTR                szProductCode,
  [in, optional] LPCWSTR                szUserSid,
  [in]           MSIINSTALLCONTEXT      dwContext,
  [in]           DWORD                  cPatchInfo,
  [in]           PMSIPATCHSEQUENCEINFOW pPatchInfo
);