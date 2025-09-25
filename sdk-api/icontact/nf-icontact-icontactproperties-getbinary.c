HRESULT GetBinary(
  [in]      LPCWSTR pszPropertyName,
  [in]      DWORD   dwFlags,
  [in, out] LPWSTR  pszContentType,
  [in]      DWORD   cchContentType,
  [in, out] DWORD   *pdwcchContentTypeRequired,
  [out]     IStream **ppStream
);