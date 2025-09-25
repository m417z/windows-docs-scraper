UINT MsiEnumPatchesExA(
  [in, optional]      LPCSTR            szProductCode,
  [in, optional]      LPCSTR            szUserSid,
  [in]                DWORD             dwContext,
  [in]                DWORD             dwFilter,
  [in]                DWORD             dwIndex,
  [out, optional]     CHAR [39]         szPatchCode,
  [out, optional]     CHAR [39]         szTargetProductCode,
  [out, optional]     MSIINSTALLCONTEXT *pdwTargetProductContext,
  [out, optional]     LPSTR             szTargetUserSid,
  [in, out, optional] LPDWORD           pcchTargetUserSid
);