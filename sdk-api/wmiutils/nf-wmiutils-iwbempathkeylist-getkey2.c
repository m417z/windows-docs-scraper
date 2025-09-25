HRESULT GetKey2(
  [in]      ULONG   uKeyIx,
  [in]      ULONG   uFlags,
  [in, out] ULONG   *puNameBufSize,
  [out]     LPWSTR  pszKeyName,
  [out]     VARIANT *pKeyValue,
  [out]     ULONG   *puApparentCimType
);