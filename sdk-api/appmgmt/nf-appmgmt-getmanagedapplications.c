DWORD GetManagedApplications(
  [in]  GUID                *pCategory,
  [in]  DWORD               dwQueryFlags,
  [in]  DWORD               dwInfoLevel,
  [out] LPDWORD             pdwApps,
  [out] PMANAGEDAPPLICATION *prgManagedApps
);