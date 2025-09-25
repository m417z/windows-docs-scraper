DWORD VerFindFileA(
  [in]           DWORD  uFlags,
  [in]           LPCSTR szFileName,
  [in, optional] LPCSTR szWinDir,
  [in]           LPCSTR szAppDir,
  [out]          LPSTR  szCurDir,
  [in, out]      PUINT  puCurDirLen,
  [out]          LPSTR  szDestDir,
  [in, out]      PUINT  puDestDirLen
);