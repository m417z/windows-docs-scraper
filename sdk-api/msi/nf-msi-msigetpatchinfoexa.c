UINT MsiGetPatchInfoExA(
  [in]            LPCSTR            szPatchCode,
  [in]            LPCSTR            szProductCode,
  [in]            LPCSTR            szUserSid,
  [in]            MSIINSTALLCONTEXT dwContext,
  [in]            LPCSTR            szProperty,
  [out, optional] LPSTR             lpValue,
  [in, out]       LPDWORD           pcchValue
);