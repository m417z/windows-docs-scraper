LSTATUS SHRegOpenUSKeyA(
  [in]           LPCSTR  pszPath,
  [in]           REGSAM  samDesired,
  [in, optional] HUSKEY  hRelativeUSKey,
  [out]          PHUSKEY phNewUSKey,
  [in]           BOOL    fIgnoreHKCU
);