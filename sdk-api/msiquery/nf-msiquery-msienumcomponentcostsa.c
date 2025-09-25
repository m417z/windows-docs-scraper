UINT MsiEnumComponentCostsA(
  [in]      MSIHANDLE    hInstall,
  [in]      LPCSTR       szComponent,
  [in]      DWORD        dwIndex,
  [in]      INSTALLSTATE iState,
  [out]     LPSTR        szDriveBuf,
  [in, out] LPDWORD      pcchDriveBuf,
  [out]     LPINT        piCost,
  [out]     LPINT        piTempCost
);