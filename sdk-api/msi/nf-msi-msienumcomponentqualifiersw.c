UINT MsiEnumComponentQualifiersW(
  [in]      LPCWSTR szComponent,
  [in]      DWORD   iIndex,
  [out]     LPWSTR  lpQualifierBuf,
  [in, out] LPDWORD pcchQualifierBuf,
  [out]     LPWSTR  lpApplicationDataBuf,
  [in, out] LPDWORD pcchApplicationDataBuf
);