UINT MsiEnumPatchesW(
  [in]      LPCWSTR szProduct,
  [in]      DWORD   iPatchIndex,
  [out]     LPWSTR  lpPatchBuf,
  [out]     LPWSTR  lpTransformsBuf,
  [in, out] LPDWORD pcchTransformsBuf
);