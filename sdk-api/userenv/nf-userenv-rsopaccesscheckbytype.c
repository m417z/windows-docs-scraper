USERENVAPI HRESULT RsopAccessCheckByType(
  [in]  PSECURITY_DESCRIPTOR pSecurityDescriptor,
  [in]  PSID                 pPrincipalSelfSid,
  [in]  PRSOPTOKEN           pRsopToken,
  [in]  DWORD                dwDesiredAccessMask,
  [in]  POBJECT_TYPE_LIST    pObjectTypeList,
  [in]  DWORD                ObjectTypeListLength,
  [in]  PGENERIC_MAPPING     pGenericMapping,
  [in]  PPRIVILEGE_SET       pPrivilegeSet,
  [in]  LPDWORD              pdwPrivilegeSetLength,
  [out] LPDWORD              pdwGrantedAccessMask,
  [out] LPBOOL               pbAccessStatus
);