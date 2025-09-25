LWSTDAPI SHCreateStreamOnFileEx(
  [in]           LPCWSTR pszFile,
  [in]           DWORD   grfMode,
  [in]           DWORD   dwAttributes,
  [in]           BOOL    fCreate,
  [in, optional] IStream *pstmTemplate,
  [out]          IStream **ppstm
);