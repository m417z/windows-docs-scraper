DWORD SetEntriesInAclW(
  [in]           ULONG              cCountOfExplicitEntries,
  [in, optional] PEXPLICIT_ACCESS_W pListOfExplicitEntries,
  [in, optional] PACL               OldAcl,
  [out]          PACL               *NewAcl
);