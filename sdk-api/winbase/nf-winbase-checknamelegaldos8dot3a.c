BOOL CheckNameLegalDOS8Dot3A(
  [in]            LPCSTR lpName,
  [out, optional] LPSTR  lpOemName,
  [in]            DWORD  OemNameSize,
  [out, optional] PBOOL  pbNameContainsSpaces,
  [out]           PBOOL  pbNameLegal
);