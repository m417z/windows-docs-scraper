SHSTDAPI SHGetPropertyStoreFromParsingName(
  [in]           PCWSTR                pszPath,
  [in, optional] IBindCtx              *pbc,
  [in]           GETPROPERTYSTOREFLAGS flags,
  [in]           REFIID                riid,
  [out]          void                  **ppv
);