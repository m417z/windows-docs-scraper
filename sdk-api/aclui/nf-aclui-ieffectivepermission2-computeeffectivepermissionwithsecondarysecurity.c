HRESULT ComputeEffectivePermissionWithSecondarySecurity(
  [in]           PSID                                   pSid,
  [in, optional] PSID                                   pDeviceSid,
  [in, optional] PCWSTR                                 pszServerName,
  [in]           PSECURITY_OBJECT                       pSecurityObjects,
  [in]           DWORD                                  dwSecurityObjectCount,
  [in, optional] PTOKEN_GROUPS                          pUserGroups,
  [in, optional] PAUTHZ_SID_OPERATION                   pAuthzUserGroupsOperations,
  [in, optional] PTOKEN_GROUPS                          pDeviceGroups,
  [in, optional] PAUTHZ_SID_OPERATION                   pAuthzDeviceGroupsOperations,
  [in, optional] PAUTHZ_SECURITY_ATTRIBUTES_INFORMATION pAuthzUserClaims,
  [in, optional] PAUTHZ_SECURITY_ATTRIBUTE_OPERATION    pAuthzUserClaimsOperations,
  [in, optional] PAUTHZ_SECURITY_ATTRIBUTES_INFORMATION pAuthzDeviceClaims,
  [in, optional] PAUTHZ_SECURITY_ATTRIBUTE_OPERATION    pAuthzDeviceClaimsOperations,
  [in, out]      PEFFPERM_RESULT_LIST                   pEffpermResultLists
);