HRESULT GetAccessRights(
  [in]  const GUID *pguidObjectType,
  [in]  DWORD      dwFlags,
  [out] PSI_ACCESS *ppAccess,
  [out] ULONG      *pcAccesses,
  [out] ULONG      *piDefaultAccess
);