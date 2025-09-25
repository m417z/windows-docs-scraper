UINT MsiDeterminePatchSequenceA(
  [in]           LPCSTR                 szProductCode,
  [in, optional] LPCSTR                 szUserSid,
  [in]           MSIINSTALLCONTEXT      dwContext,
  [in]           DWORD                  cPatchInfo,
  [in]           PMSIPATCHSEQUENCEINFOA pPatchInfo
);