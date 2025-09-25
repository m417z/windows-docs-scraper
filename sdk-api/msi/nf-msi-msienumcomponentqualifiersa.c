UINT MsiEnumComponentQualifiersA(
  [in]      LPCSTR  szComponent,
  [in]      DWORD   iIndex,
  [out]     LPSTR   lpQualifierBuf,
  [in, out] LPDWORD pcchQualifierBuf,
  [out]     LPSTR   lpApplicationDataBuf,
  [in, out] LPDWORD pcchApplicationDataBuf
);