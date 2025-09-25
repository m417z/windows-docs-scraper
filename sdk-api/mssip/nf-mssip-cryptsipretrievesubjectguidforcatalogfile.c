BOOL CryptSIPRetrieveSubjectGuidForCatalogFile(
  [in]           LPCWSTR FileName,
  [in, optional] HANDLE  hFileIn,
  [out]          GUID    *pgSubject
);