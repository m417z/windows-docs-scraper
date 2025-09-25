UINT MsiEnumPatchesA(
  [in]      LPCSTR  szProduct,
  [in]      DWORD   iPatchIndex,
  [out]     LPSTR   lpPatchBuf,
  [out]     LPSTR   lpTransformsBuf,
  [in, out] LPDWORD pcchTransformsBuf
);