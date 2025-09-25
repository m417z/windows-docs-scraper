BOOL AccessCheck(
  [in]            PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [in]            HANDLE               ClientToken,
  [in]            DWORD                DesiredAccess,
  [in]            PGENERIC_MAPPING     GenericMapping,
  [out, optional] PPRIVILEGE_SET       PrivilegeSet,
  [in, out]       LPDWORD              PrivilegeSetLength,
  [out]           LPDWORD              GrantedAccess,
  [out]           LPBOOL               AccessStatus
);