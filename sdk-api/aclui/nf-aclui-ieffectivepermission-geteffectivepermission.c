HRESULT GetEffectivePermission(
  [in]  const GUID           *pguidObjectType,
  [in]  PSID                 pUserSid,
  [in]  LPCWSTR              pszServerName,
  [in]  PSECURITY_DESCRIPTOR pSD,
  [out] POBJECT_TYPE_LIST    *ppObjectTypeList,
  [out] ULONG                *pcObjectTypeListLength,
  [out] PACCESS_MASK         *ppGrantedAccessList,
  [out] ULONG                *pcGrantedAccessListLength
);