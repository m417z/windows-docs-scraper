UINT MsiGetPatchFileListA(
  [in]      LPCSTR    szProductCode,
  [in]      LPCSTR    szPatchPackages,
  [in, out] LPDWORD   pcFiles,
  [in, out] MSIHANDLE **pphFileRecords
);