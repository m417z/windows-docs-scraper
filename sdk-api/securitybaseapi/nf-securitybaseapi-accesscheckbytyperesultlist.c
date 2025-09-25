BOOL AccessCheckByTypeResultList(
  [in]                PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [in, optional]      PSID                 PrincipalSelfSid,
  [in]                HANDLE               ClientToken,
  [in]                DWORD                DesiredAccess,
  [in, out, optional] POBJECT_TYPE_LIST    ObjectTypeList,
  [in]                DWORD                ObjectTypeListLength,
  [out]               PGENERIC_MAPPING     GenericMapping,
  [out, optional]     PPRIVILEGE_SET       PrivilegeSet,
  [in, out]           LPDWORD              PrivilegeSetLength,
  [out]               LPDWORD              GrantedAccessList,
  [out]               LPDWORD              AccessStatusList
);