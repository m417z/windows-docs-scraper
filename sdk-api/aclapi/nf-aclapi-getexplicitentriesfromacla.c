DWORD GetExplicitEntriesFromAclA(
  [in]  PACL               pacl,
  [out] PULONG             pcCountOfExplicitEntries,
  [out] PEXPLICIT_ACCESS_A *pListOfExplicitEntries
);