SHSTDAPI SHDefExtractIconA(
  [in]            LPCSTR pszIconFile,
                  int    iIndex,
  [in]            UINT   uFlags,
  [out, optional] HICON  *phiconLarge,
  [out, optional] HICON  *phiconSmall,
                  UINT   nIconSize
);