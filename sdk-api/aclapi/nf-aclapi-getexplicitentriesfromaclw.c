DWORD GetExplicitEntriesFromAclW(
  [in]  PACL               pacl,
  [out] PULONG             pcCountOfExplicitEntries,
  [out] PEXPLICIT_ACCESS_W *pListOfExplicitEntries
);