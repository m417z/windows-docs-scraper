UINT MsiEnumComponentCostsW(
  [in]      MSIHANDLE    hInstall,
  [in]      LPCWSTR      szComponent,
  [in]      DWORD        dwIndex,
  [in]      INSTALLSTATE iState,
  [out]     LPWSTR       szDriveBuf,
  [in, out] LPDWORD      pcchDriveBuf,
  [out]     LPINT        piCost,
  [out]     LPINT        piTempCost
);