HRESULT GetKey(
  [in]      ULONG  uKeyIx,
  [in]      ULONG  uFlags,
  [in, out] ULONG  *puNameBufSize,
  [in, out] LPWSTR pszKeyName,
  [in, out] ULONG  *puKeyValBufSize,
  [in, out] LPVOID pKeyVal,
  [in, out] ULONG  *puApparentCimType
);