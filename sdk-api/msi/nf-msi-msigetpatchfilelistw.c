UINT MsiGetPatchFileListW(
  [in]      LPCWSTR   szProductCode,
  [in]      LPCWSTR   szPatchPackages,
  [in, out] LPDWORD   pcFiles,
  [in, out] MSIHANDLE **pphFileRecords
);