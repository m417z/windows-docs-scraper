INSTALLSTATE MsiGetComponentPathExA(
  [in]                LPCSTR            szProductCode,
  [in]                LPCSTR            szComponentCode,
  [in, optional]      LPCSTR            szUserSid,
  [in, optional]      MSIINSTALLCONTEXT dwContext,
  [out, optional]     LPSTR             lpOutPathBuffer,
  [in, out, optional] LPDWORD           pcchOutPathBuffer
);