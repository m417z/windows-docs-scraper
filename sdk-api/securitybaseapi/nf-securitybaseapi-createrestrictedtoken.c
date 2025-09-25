BOOL CreateRestrictedToken(
  [in]           HANDLE               ExistingTokenHandle,
  [in]           DWORD                Flags,
  [in]           DWORD                DisableSidCount,
  [in, optional] PSID_AND_ATTRIBUTES  SidsToDisable,
  [in]           DWORD                DeletePrivilegeCount,
  [in, optional] PLUID_AND_ATTRIBUTES PrivilegesToDelete,
  [in]           DWORD                RestrictedSidCount,
  [in, optional] PSID_AND_ATTRIBUTES  SidsToRestrict,
  [out]          PHANDLE              NewTokenHandle
);