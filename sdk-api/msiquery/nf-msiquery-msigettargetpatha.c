UINT MsiGetTargetPathA(
  [in]      MSIHANDLE hInstall,
  [in]      LPCSTR    szFolder,
  [out]     LPSTR     szPathBuf,
  [in, out] LPDWORD   pcchPathBuf
);