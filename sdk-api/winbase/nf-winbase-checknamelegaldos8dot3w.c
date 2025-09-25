BOOL CheckNameLegalDOS8Dot3W(
  [in]            LPCWSTR lpName,
  [out, optional] LPSTR   lpOemName,
  [in]            DWORD   OemNameSize,
  [out, optional] PBOOL   pbNameContainsSpaces,
  [out]           PBOOL   pbNameLegal
);