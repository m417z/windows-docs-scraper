HRESULT GetStream(
  [in]      LPCWSTR        pszObjectID,
  [in]      REFPROPERTYKEY Key,
  [in]      const DWORD    dwMode,
  [in, out] DWORD          *pdwOptimalBufferSize,
  [out]     IStream        **ppStream
);