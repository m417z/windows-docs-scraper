LSTATUS SHRegOpenUSKeyW(
                 LPCWSTR pwzPath,
  [in]           REGSAM  samDesired,
  [in, optional] HUSKEY  hRelativeUSKey,
  [out]          PHUSKEY phNewUSKey,
  [in]           BOOL    fIgnoreHKCU
);