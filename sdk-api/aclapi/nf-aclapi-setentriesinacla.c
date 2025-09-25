DWORD SetEntriesInAclA(
  [in]           ULONG              cCountOfExplicitEntries,
  [in, optional] PEXPLICIT_ACCESS_A pListOfExplicitEntries,
  [in, optional] PACL               OldAcl,
  [out]          PACL               *NewAcl
);