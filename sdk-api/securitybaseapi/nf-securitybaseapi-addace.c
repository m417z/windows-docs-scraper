BOOL AddAce(
  [in, out] PACL   pAcl,
  [in]      DWORD  dwAceRevision,
  [in]      DWORD  dwStartingAceIndex,
  [in]      LPVOID pAceList,
  [in]      DWORD  nAceListLength
);