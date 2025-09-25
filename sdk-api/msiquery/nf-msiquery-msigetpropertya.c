UINT MsiGetPropertyA(
  [in]      MSIHANDLE hInstall,
  [in]      LPCSTR    szName,
  [out]     LPSTR     szValueBuf,
  [in, out] LPDWORD   pcchValueBuf
);