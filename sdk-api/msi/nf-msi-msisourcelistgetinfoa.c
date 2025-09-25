UINT MsiSourceListGetInfoA(
  [in]                LPCSTR            szProductCodeOrPatchCode,
  [in, optional]      LPCSTR            szUserSid,
  [in]                MSIINSTALLCONTEXT dwContext,
  [in]                DWORD             dwOptions,
  [in]                LPCSTR            szProperty,
  [out, optional]     LPSTR             szValue,
  [in, out, optional] LPDWORD           pcchValue
);