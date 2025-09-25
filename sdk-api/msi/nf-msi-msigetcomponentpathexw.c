INSTALLSTATE MsiGetComponentPathExW(
  [in]                LPCWSTR           szProductCode,
  [in]                LPCWSTR           szComponentCode,
  [in, optional]      LPCWSTR           szUserSid,
  [in, optional]      MSIINSTALLCONTEXT dwContext,
  [out, optional]     LPWSTR            lpOutPathBuffer,
  [in, out, optional] LPDWORD           pcchOutPathBuffer
);