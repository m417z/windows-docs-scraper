BOOL DIAMONDAPI FCIAddFile(
  [in] HFCI                 hfci,
  [in] LPSTR                pszSourceFile,
  [in] LPSTR                pszFileName,
  [in] BOOL                 fExecute,
  [in] PFNFCIGETNEXTCABINET pfnfcignc,
  [in] PFNFCISTATUS         pfnfcis,
  [in] PFNFCIGETOPENINFO    pfnfcigoi,
  [in] TCOMP                typeCompress
);