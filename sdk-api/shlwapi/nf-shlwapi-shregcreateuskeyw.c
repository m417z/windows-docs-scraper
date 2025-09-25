LSTATUS SHRegCreateUSKeyW(
                 LPCWSTR pwzPath,
  [in]           REGSAM  samDesired,
  [in, optional] HUSKEY  hRelativeUSKey,
  [out]          PHUSKEY phNewUSKey,
  [in]           DWORD   dwFlags
);