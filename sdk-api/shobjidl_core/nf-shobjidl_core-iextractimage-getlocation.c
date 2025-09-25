HRESULT GetLocation(
  [out]     LPWSTR     pszPathBuffer,
  [in]      DWORD      cch,
  [out]     DWORD      *pdwPriority,
  [in]      const SIZE *prgSize,
  [in]      DWORD      dwRecClrDepth,
  [in, out] DWORD      *pdwFlags
);